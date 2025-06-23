cmake_minimum_required(VERSION 3.31)
project(pangolin VERSION "0.0.1" DESCRIPTION "Messaging app that operates on the CLI and uses PGP encryption for messages")

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 20)

find_library(METAL_LIBRARY Metal REQUIRED)
find_library(FOUNDATION_LIBRARY Foundation REQUIRED)
find_library(QUARTS_CORE QuartzCore REQUIRED)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/get_resources.cpp
        src/connections/connect.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ./Libraries/metal-cpp/
)

find_package(nlohmann_json REQUIRED)

target_link_libraries(${PROJECT_NAME}
        nlohmann_json::nlohmann_json
        ${METAL_LIBRARY}
        ${FOUNDATION_LIBRARY}
        ${QUARTS_CORE}
)