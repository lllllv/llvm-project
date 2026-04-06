
# =============================================================================
# CMake initial cache for MyX86 backend
# Usage: cmake -C <path_for_this_file> -G Ninja -S llvm -B build [-DCMAKE_INSTALL_PREFIX=<path>]
# Template: set(var  "value"  CACHE  Type  "description"  FORCE)
# =============================================================================

set(CMAKE_EXPORT_COMPILE_COMMANDS  "ON"  CACHE  STRING  "Compile commands"  FORCE)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
set(LLVM_ENABLE_PROJECTS  "clang"  CACHE  STRING  "Enable projects"  FORCE)
set(BUILD_SHARED_LIBS  "ON"  CACHE  STRING  "Build shared libs"  FORCE)
set(LLVM_USE_LINKER  "gold"  CACHE  STRING  "Linker used"  FORCE)
set(LLVM_ENABLE_ABI_BREAKING_CHECKS  "ON"  CACHE  STRING  "Enable abi breaking checks"  FORCE)
set(LLVM_CCACHE_BUILD "ON" CACHE STRING "Using ccache to speed up build" FORCE)
#set(CMAKE_INSTALL_PREFIX  "./output/debug"  CACHE  STRING  "Install path"  FORCE)
