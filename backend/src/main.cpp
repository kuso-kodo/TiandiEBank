#include <iostream>
#include <sqlite_orm.h>

using namespace sqlite_orm;

int main()
{
    struct Contact
    {
        int id = 0;
        std::string firstName;
        std::string lastName;
        std::string email;
        std::string phone;
    };

    struct Product
    {
        int id = 0;
        std::string name;
        float listPrice = 0;
        float discount = 0;
    };
    auto storage = make_storage("a.db",
                                make_table("contacts",
                                           make_column("contact_id", &Contact::id, primary_key()),
                                           make_column("first_name", &Contact::firstName),
                                           make_column("last_name", &Contact::lastName),
                                           make_column("email", &Contact::email),
                                           make_column("phone", &Contact::phone),
                                           check(length(&Contact::phone) >= 10)),
                                make_table("products",
                                           make_column("product_id", &Product::id, primary_key()),
                                           make_column("product_name", &Product::name),
                                           make_column("list_price", &Product::listPrice),
                                           make_column("discount", &Product::discount, default_value(0)),
                                           check(c(&Product::listPrice) >= &Product::discount and
                                                 c(&Product::discount) >= 0 and c(&Product::listPrice) >= 0)));
    storage.sync_schema();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
