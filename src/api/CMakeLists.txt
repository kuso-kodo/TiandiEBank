add_library(api OBJECT
    account.cpp
    transaction.cpp
)

target_include_directories(api PRIVATE . ../include)
