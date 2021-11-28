add_subdirectory(db)
add_subdirectory(service)

include_directories(include)

add_executable(TiandiEBank main.cpp)

target_link_libraries(TiandiEBank sqlite3 wolfssl db service)
