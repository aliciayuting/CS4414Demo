#include "llama.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

std::vector<float> get_embeddings(llama_context* ctx, llama_model* model, const std::string& text) {
    // Get vocab for tokenization
    const llama_vocab* vocab = llama_model_get_vocab(model);
    
    // Tokenize the input text
    const int n_tokens_max = llama_n_ctx(ctx);
    std::vector<llama_token> tokens(n_tokens_max);
    
    const int n_tokens = llama_tokenize(
        vocab,
        text.c_str(),
        text.length(),
        tokens.data(),
        tokens.size(),
        true,   // add_bos
        false   // special
    );
    
    if (n_tokens < 0) {
        std::cerr << "Error: failed to tokenize text" << std::endl;
        return {};
    }
    
    tokens.resize(n_tokens);
    
    // Create a batch
    llama_batch batch = llama_batch_init(n_tokens, 0, 1);
    
    // Add tokens to batch manually - all tokens for sequence embedding
    for (int i = 0; i < n_tokens; i++) {
        batch.token[i] = tokens[i];
        batch.pos[i] = i;
        batch.n_seq_id[i] = 1;
        batch.seq_id[i][0] = 0;
        batch.logits[i] = false;  // Not needed for embeddings
    }
    batch.n_tokens = n_tokens;
    
    // Use encode for embedding models
    if (llama_encode(ctx, batch) != 0) {
        std::cerr << "Error: failed to encode" << std::endl;
        llama_batch_free(batch);
        return {};
    }
    
    // Get sequence embeddings (for BERT-style models, this gives pooled embeddings)
    const int n_embd = llama_model_n_embd(model);
    const float* embeddings = llama_get_embeddings_seq(ctx, 0);  // sequence 0
    
    std::vector<float> result;
    if (embeddings != nullptr) {
        result.assign(embeddings, embeddings + n_embd);
    } else {
        std::cerr << "Warning: embeddings are null, trying alternative method" << std::endl;
        // Fallback to regular embeddings
        embeddings = llama_get_embeddings(ctx);
        if (embeddings != nullptr) {
            result.assign(embeddings, embeddings + n_embd);
        }
    }
    
    llama_batch_free(batch);
    return result;
}

int main(int argc, char** argv) {
    llama_log_set([](enum llama_log_level level, const char * text, void * user_data) {
        // Do nothing - suppress all logs
    }, nullptr);
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <model_path> <text>" << std::endl;
        return 1;
    }
    
    const char* model_path = argv[1];
    const std::string text = argv[2];
    
    // Initialize
    llama_backend_init();
    
    // Load model
    llama_model_params model_params = llama_model_default_params();
    llama_model* model = llama_model_load_from_file(model_path, model_params);
    if (!model) {
        std::cerr << "Error: failed to load model" << std::endl;
        return 1;
    }
    
    // Create context with embeddings enabled
    llama_context_params ctx_params = llama_context_default_params();
    ctx_params.n_ctx = 512;
    ctx_params.embeddings = true;  // Important: enable embeddings mode
    
    llama_context* ctx = llama_init_from_model(model, ctx_params);
    if (!ctx) {
        std::cerr << "Error: failed to create context" << std::endl;
        llama_model_free(model);
        return 1;
    }
    
    // Generate embeddings
    std::vector<float> embeddings = get_embeddings(ctx, model, text);
    
    // Print embeddings
    std::cout << "Embedding dimension: " << embeddings.size() << std::endl;
    // for (size_t i = 0; i < embeddings.size(); i++) {
    //     std::cout << embeddings[i];
    //     if (i < embeddings.size() - 1) std::cout << " ";
    // }
    // std::cout << std::endl;
    
    // Cleanup
    llama_free(ctx);
    llama_model_free(model);
    llama_backend_free();
    
    return 0;
}