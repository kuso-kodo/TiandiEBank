add_library(service OBJECT
    account.cpp
    transaction.cpp
)

target_include_directories(service PRIVATE . ../include)
