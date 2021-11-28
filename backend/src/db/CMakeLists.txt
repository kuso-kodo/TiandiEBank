add_library(db OBJECT
    init.cpp
)

target_include_directories(db PRIVATE . ../include)
