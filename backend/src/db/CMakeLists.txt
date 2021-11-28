add_library(db OBJECT
    init.cpp
    account.cpp
    transaction.cpp
)

target_include_directories(db PRIVATE . ../include)
