#include <iostream>
#include <api/account.h>
#include <api/transaction.h>
#include <db/db.h>
#include <httplib.h>

int main()
{
    db::init_storage();
    httplib::Server server;
    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });
    server.Post("/account/new", api::account::account_new);
    server.Post("/account/login", api::account::account_login);
    server.Get("/account/info", api::account::account_info);
    server.Post("/account/update", api::account::account_update);
    server.Post("/account/delete", api::account::account_delete);
    server.Post("/transaction/deposit", api::transaction::transaction_deposit);
    server.Post("/transaction/withdraw", api::transaction::transaction_withdraw);
    server.Post("/transaction/transfer", api::transaction::transaction_transfer);
    server.Get("/transaction/get_transactions", api::transaction::transaction_get_transactions);
    server.listen("localhost", 1234);
    return 0;
}
