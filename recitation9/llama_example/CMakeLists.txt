cmake_minimum_required(VERSION 3.16)
project(llama_simple CXX)

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
add_executable(run run_llama.cpp)

target_include_directories(run PRIVATE
  "${LLAMA_INCLUDE_DIR}"
  "${GGML_INCLUDE_DIR}"
)

# Prefer per-target link directories over global link_directories
target_link_directories(run PRIVATE "${LLAMA_LIB_DIR}")

# Threads (pthread)
find_package(Threads REQUIRED)

# Link the same libs as your working g++ command (CPU-only build of ggml)
target_link_libraries(run PRIVATE
  llama
  ggml
  ggml-base
  ggml-cpu
  Threads::Threads
  dl
  m
)

# Optional: add OpenMP if available (harmless if not found)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  target_link_libraries(run PRIVATE OpenMP::OpenMP_CXX)
endif()

# ---- RPATH so the binary runs without LD_LIBRARY_PATH ----
set_target_properties(run PROPERTIES
  BUILD_RPATH   "${LLAMA_LIB_DIR}"
  INSTALL_RPATH "${LLAMA_LIB_DIR}"
)