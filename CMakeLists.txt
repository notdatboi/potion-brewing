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

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB HDRS ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(PotionBrewing ${SRCS} ${HDRS})

cmake_print_variables(Boost_LIBRARIES)
target_include_directories(PotionBrewing PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/SDL/include" "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(PotionBrewing PUBLIC
  Boost::asio
  SDL3
  pthread)
