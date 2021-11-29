#pragma once
#include <optional>
#include <httplib.h>

namespace api {
    namespace account {
        std::optional<int> account_id(const httplib::Request& req);
        void account_new(const httplib::Request& req, httplib::Response& res);
        void account_login(const httplib::Request& req, httplib::Response& res);
        void account_info(const httplib::Request& req, httplib::Response& res);
        void account_update(const httplib::Request& req, httplib::Response& res);
        void account_delete(const httplib::Request& req, httplib::Response& res);
    }
}