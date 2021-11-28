#include <iostream>
#include <db/db.h>

int main()
{
    db::init_storage();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
