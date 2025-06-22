cmake_minimum_required(VERSION 3.31)
project(cli_msg_app)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json REQUIRED)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

add_executable(${PROJECT_NAME} src/main.cpp)
