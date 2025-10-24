# Introduction to build


## Building Llama.cpp from source code to local directory


https://github.com/ggml-org/llama.cpp/blob/master/docs/build.md 


### To get the code

```
git clone https://github.com/ggml-org/llama.cpp
cd llama.cpp
```

### CMake install to designated local directory

A commonly used install directory is local ```~/opt_dev```

```
mkdir ~/opt_dev

mkdir build && cd build

cmake .. -DCMAKE_INSTALL_PREFIX=~/opt_dev -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
make install
```

### Add to PATH

Add the library installation directory to PATH, so that when you compile your CPP code using this library, it will be able to find it

```
export PATH=~/opt_dev/llama/bin:$PATH
export LD_LIBRARY_PATH=~/opt_dev/llama/lib:$LD_LIBRARY_PATH
```

You can also append this to ```~/.bashrc``` so that next time when you open the terminal it will be automatically loaded

```
echo "export PATH=~/opt_dev/llama/bin:\$PATH" >> ~/.bashrc
echo "export LD_LIBRARY_PATH=~/opt_dev/llama/lib:\$LD_LIBRARY_PATH" >> ~/.bashrc
```

Then reload
```
source ~/.bashrc
```