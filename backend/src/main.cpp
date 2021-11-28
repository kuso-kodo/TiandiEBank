#include <iostream>
#include <jwt-cpp/jwt.h>
#include <db/db.h>
#include <service/account.h>
#include <httplib.h>

int main()
{
    db::init_storage();
    std::cout << "Hello, World!" << std::endl;
    std::string token = service::account::login_account(1, "1145141919810").value_or("error");
    auto decoded = jwt::decode(token);

    for(auto& e : decoded.get_payload_claims())
        std::cout << e.first << " = " << e.second << std::endl;

    std::cout << service::account::extract_id(token).value_or(-1) << std::endl;

    httplib::Server server;
    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });
    server.listen("localhost", 1234);
    return 0;
}
