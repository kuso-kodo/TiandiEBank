#pragma once
#include <httplib.h>

namespace api {
    namespace transaction {
        void transaction_deposit(const httplib::Request& req, httplib::Response& res);
        void transaction_withdraw(const httplib::Request& req, httplib::Response& res);
        void transaction_transfer(const httplib::Request& req, httplib::Response& res);
        void transaction_get_transactions(const httplib::Request& req, httplib::Response& res);
    }
}