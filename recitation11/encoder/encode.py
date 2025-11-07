from llama_cpp import Llama

# Path to your GGUF embedding model, e.g. BGE / nomic-embed
MODEL_PATH = "./bge-base-en-v1.5-f32.gguf"
TEXT = "hello world"

# Create a Llama object with embeddings enabled.
llm = Llama(
    model_path=MODEL_PATH,
    n_ctx=512,
    embedding=True,   # <- important, like ctx_params.embeddings = true
    logits_all=False, # we don't need logits
)

# Get embeddings (this uses llama_encode + llama_get_embeddings under the hood)
result = llm.create_embedding(
    input=TEXT
)

# Result is a dict; embeddings are under ["data"][0]["embedding"]
embedding = result["data"][0]["embedding"]

print("Embedding dimension:", len(embedding))
# print(embedding)   # uncomment if you want to see all values