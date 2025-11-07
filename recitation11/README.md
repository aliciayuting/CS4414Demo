# Introduction to build llama.cpp and FAISS

## CPP version

In recitation9, we introduced how to build llama.cpp from the cpp version and use it to run model inference. If you want to work with the C++ API please refer to that README for more information

In this recitation, we will look into how to build llama.cpp Python (https://github.com/abetlen/llama-cpp-python ) and faiss CPU Python (https://github.com/facebookresearch/faiss) 

## 1. Installation
You can install by running the command in ```dependencies.sh``` on ugclinux cluster

## 2. Working with the repo

### llama.cpp encoder
To download the encoder model, you can use the command 
```
wget -c "https://huggingface.co/CompendiumLabs/bge-base-en-v1.5-gguf/resolve/main/bgebase-
en-v1.5-f32.gguf?download=true" -O bge-base-en-v1.5-f32.gguf
```

We recommend you to read into details about the tutorial in the llama.cpp python README: https://github.com/abetlen/llama-cpp-python/blob/main/README.md 

In our demo of encode.py, it came from this tutorial: https://github.com/abetlen/llama-cpp-python/blob/main/examples/high_level_api/high_level_api_embedding.py 

### FAISS ANN search
For FAISS, they also provide good tutorial with CPP and Python API: https://github.com/facebookresearch/faiss/tree/main/tutorial 

We suggest you to read and understand their code, to customize your implementation.

