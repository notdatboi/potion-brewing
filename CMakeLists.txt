cmake_minimum_required(VERSION 3.15)

project(PotionBrewing VERSION 1.0)

add_library(PotionBrewingCompilerFlags INTERFACE)
target_compile_features(PotionBrewingCompilerFlags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
#set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(PotionBrewingCompilerFlags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
#  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CURRENT_SOURCE_DIR)

set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/boost")
add_subdirectory(boost)
add_subdirectory(SDL)

add_executable(PotionBrewing main.cpp)

cmake_print_variables(Boost_LIBRARIES)
target_include_directories(PotionBrewing PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/SDL/include")

target_link_libraries(PotionBrewing PUBLIC
  Boost::asio
  SDL3
  pthread)
