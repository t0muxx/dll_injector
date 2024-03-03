cmake_minimum_required(VERSION 3.1...3.28)

set(LIBNAME "libfenetre")

project(
  dll_injector
  VERSION 1.0
  LANGUAGES CXX)




add_subdirectory("${LIBNAME}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/${LIBNAME}"
                          )

target_link_libraries(${PROJECT_NAME} PUBLIC "${LIBNAME}")

