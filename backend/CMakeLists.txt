cmake_minimum_required(VERSION 3.19)
project(TiandiEBank)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    third_party/cpp-httplib
    third_party/json/single_include/nlohmann
    third_party/sqlite_orm/
    third_party/sqlite/
)

add_subdirectory(src)
