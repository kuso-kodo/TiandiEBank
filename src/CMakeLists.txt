add_subdirectory(api)
add_subdirectory(db)
add_subdirectory(service)

include_directories(include)

add_executable(TiandiEBankServer server.cpp)
add_executable(TiandiEBankClient client.cpp)

target_link_libraries(TiandiEBankServer sqlite3 wolfssl db service api)