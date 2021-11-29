#include <api/account.h>
#include <service/account.h>
#include <nlohmann/json.hpp>

namespace api
{
    namespace account
    {
        std::optional<int> account_id(const httplib::Request &req)
        {
            if (req.has_header("token"))
            {
                auto token = req.get_header_value("token");
                return service::account::extract_id(token);
            }
            else
            {
                return std::nullopt;
            }
        }

        void account_new(const httplib::Request &req, httplib::Response &res)
        {
            auto first_name = req.get_param_value("first_name");
            auto last_name = req.get_param_value("last_name");
            auto phone = req.get_param_value("phone");
            auto password = req.get_param_value("password");
            if (first_name.empty() || last_name.empty() || phone.empty() || password.empty())
            {
                res.set_content("{\"error\": \"invalid parameters\"}", "application/json");
                res.status = 400;
                return;
            }
            auto id = service::account::create_account(first_name, last_name, phone, password);
            if (id)
            {
                res.set_content(std::to_string(id), "application/json");
                res.status = 200;
            }
            else
            {
                res.set_content("{\"error\": \"failed to create account\"}", "application/json");
                res.status = 500;
            }
        }

        void account_login(const httplib::Request &req, httplib::Response &res)
        {
            auto id = req.get_param_value("id");
            auto password = req.get_param_value("password");
            if (id.empty() || password.empty())
            {
                res.set_content("{\"error\": \"invalid parameters\"}", "application/json");
                res.status = 400;
                return;
            }
            auto token = service::account::login_account(std::stoi(id), password);
            if (token.has_value())
            {
                res.set_content(token.value(), "application/json");
                res.status = 200;
            }
            else
            {
                res.set_content("{\"error\": \"failed to login\"}", "application/json");
                res.status = 500;
            }
        }

        void account_info(const httplib::Request &req, httplib::Response &res)
        {
            auto id = account_id(req);
            if (id.has_value())
            {
                auto info = service::account::get_account(id.value());
                if (info.has_value())
                {
                    nlohmann::json j;
                    j["id"] = info.value().id;
                    j["first_name"] = info.value().first_name;
                    j["last_name"] = info.value().last_name;
                    j["phone"] = info.value().phone;
                    j["balance"] = info.value().balance;
                    res.set_content(j.dump(), "application/json");
                    res.status = 200;
                }
                else
                {
                    res.set_content("{\"error\": \"failed to get account info\"}", "application/json");
                    res.status = 500;
                }
            }
            else
            {
                res.set_content("{\"error\": \"invalid token\"}", "application/json");
                res.status = 400;
            }
        }
        void account_update(const httplib::Request &req, httplib::Response &res)
        {
            auto id = account_id(req);
            if (id.has_value())
            {
                auto first_name = req.get_param_value("first_name");
                auto last_name = req.get_param_value("last_name");
                auto phone = req.get_param_value("phone");
                auto password = req.get_param_value("password");
                auto first_name_opt = first_name.empty() ? std::nullopt : std::optional<std::string>(first_name);
                auto last_name_opt = last_name.empty() ? std::nullopt : std::optional<std::string>(last_name);
                auto phone_opt = phone.empty() ? std::nullopt : std::optional<std::string>(phone);
                auto password_opt = password.empty() ? std::nullopt : std::optional<std::string>(password);
                auto token = service::account::update_account_info(id.value(), first_name_opt, last_name_opt, phone_opt, password_opt);
                if (token.has_value())
                {
                    res.set_content(token.value(), "application/json");
                    res.status = 200;
                }
                else
                {
                    res.set_content("{\"succes\": \"update account info success\"}", "application/json");
                    res.status = 200;
                }
            }
            else
            {
                res.set_content("{\"error\": \"invalid token\"}", "application/json");
                res.status = 400;
            }
        }

        void account_delete(const httplib::Request &req, httplib::Response &res)
        {
            auto id = account_id(req);
            if (id.has_value())
            {
                service::account::delete_account(id.value());
                res.set_content("{\"success\": \"account deleted\"}", "application/json");
            }
            else
            {
                res.set_content("{\"error\": \"invalid token\"}", "application/json");
                res.status = 400;
            }
        }
    }
}