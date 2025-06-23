cmake_minimum_required(VERSION 3.31)
project(pangolin VERSION "0.0.1" DESCRIPTION "Messaging app that operates on the CLI and uses PGP encryption for messages")

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/get_resources.cpp
)

find_package(nlohmann_json REQUIRED)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)