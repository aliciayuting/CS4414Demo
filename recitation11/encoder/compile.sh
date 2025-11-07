g++ -std=c++20 embedding_example.cpp \
  -I"$HOME/opt_dev/include" \
  -L"$HOME/opt_dev/lib" \
  -Wl,-rpath,"$HOME/opt_dev/lib" \
  -lllama -lggml -lggml-base -lggml-cpu \
  -lpthread -ldl -lm \
  -o encoder