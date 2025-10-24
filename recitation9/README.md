# Introduction to build

## 1. Installation

There are two ways to install. If you are running on local machine, you can follow method1; if you want to compile and run it on shared cluster, like ugclinux cornell engineering cluster, you can use method2. You can install with or without GPU depending on your hardware setting, but for the assignment in the class, we use CPU version.

### method1. Use local machine
https://github.com/ggml-org/llama.cpp/blob/master/docs/install.md 

### method2. Use ugclinux cluster

Building Llama.cpp from source code to local directory

https://github.com/ggml-org/llama.cpp/blob/master/docs/build.md 


#### 1.1 To get the code

```
git clone https://github.com/ggml-org/llama.cpp
cd llama.cpp
```

#### 1.2 CMake install to designated local directory

A commonly used install directory is local ```~/opt_dev```

```
mkdir ~/opt_dev

mkdir build && cd build

cmake .. -DCMAKE_INSTALL_PREFIX=~/opt_dev -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
make install
```

#### 1.3 Add to PATH

Add the library installation directory to PATH, so that when you compile your CPP code using this library, it will be able to find it

```
export PATH=~/opt_dev/bin:$PATH
export LD_LIBRARY_PATH=~/opt_dev/lib:$LD_LIBRARY_PATH
```

You can also append this to ```~/.bashrc``` so that next time when you open the terminal it will be automatically loaded

```
echo "export PATH=~/opt_dev/bin:\$PATH" >> ~/.bashrc
echo "export LD_LIBRARY_PATH=~/opt_dev/lib:\$LD_LIBRARY_PATH" >> ~/.bashrc
```

Then reload
```
source ~/.bashrc
```

## 2. Run Llama.cpp

### Choose a model

We can use a small model tinyllama
```
wget https://huggingface.co/TheBloke/TinyLlama-1.1B-Chat-v0.3-GGUF/resolve/main/tinyllama-1.1b-chat-v0.3.Q4_K_M.gguf
```

This can also be downloaded via llama-cli with huggingface
```
llama-cli --hf-repo TinyLlama/TinyLlama-1.1B-Chat-v0.3-GGUF --hf-file tinyllama-1.1b-chat-v0.3.Q4_K_M.gguf
```

### using llama-cli
This CLI tool is more interactive to run models

```
llama-cli -m tinyllama-1.1b-chat-v0.3.Q4_K_M.gguf \
  -c 2048 \
  -p "Explain RDMA in two sentences. "
```



### Writing CPP code using llama.cpp

https://github.com/ggml-org/llama.cpp/blob/0bcb40b48c6fc6f17ba9672625e526ab2574344b/examples/simple/simple.cpp

