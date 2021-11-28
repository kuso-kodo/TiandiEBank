#include <iostream>
#include <jwt-cpp/jwt.h>
#include <db/db.h>
#include <service/account.h>

int main()
{
    db::init_storage();
    std::cout << "Hello, World!" << std::endl;
    std::string token = service::account::login_account(1, "1145141919810").value_or("error");
    auto decoded = jwt::decode(token);

    for(auto& e : decoded.get_payload_claims())
        std::cout << e.first << " = " << e.second << std::endl;
    return 0;
}
