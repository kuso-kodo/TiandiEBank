add_subdirectory(db)

include_directories(include)

add_executable(TiandiEBank main.cpp)

target_link_libraries(TiandiEBank sqlite3 db)
