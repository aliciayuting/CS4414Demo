cmake_minimum_required(VERSION 3.16)
project(llama_embeddings CXX)

# ---- C++ standard ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Where llama.cpp was installed ----
# Change this if you installed elsewhere, or pass -DLLAMA_PREFIX=/path at configure time.
set(LLAMA_PREFIX "$ENV{HOME}/opt_dev" CACHE PATH "Install prefix of llama.cpp")

set(LLAMA_INCLUDE_DIR "${LLAMA_PREFIX}/include")
set(GGML_INCLUDE_DIR  "${LLAMA_PREFIX}/include/ggml")
set(LLAMA_LIB_DIR     "${LLAMA_PREFIX}/lib")

# ---- Target ----
add_executable(embedding_example embedding_example.cpp)

target_include_directories(embedding_example PRIVATE
  "${LLAMA_INCLUDE_DIR}"
  "${GGML_INCLUDE_DIR}"
)

# Prefer per-target link directories over global link_directories
target_link_directories(embedding_example PRIVATE "${LLAMA_LIB_DIR}")

# Threads (pthread)
find_package(Threads REQUIRED)

# Link the same libs as your working g++ command (CPU-only build of ggml)
target_link_libraries(embedding_example PRIVATE
  llama
  ggml
  ggml-base
  ggml-cpu
  Threads::Threads
  dl
  m
)


# ---- RPATH so the binary runs without LD_LIBRARY_PATH ----
set_target_properties(embedding_example PROPERTIES
  BUILD_RPATH   "${LLAMA_LIB_DIR}"
  INSTALL_RPATH "${LLAMA_LIB_DIR}"
)