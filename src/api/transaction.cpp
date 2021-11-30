#include <api/account.h>
#include <api/transaction.h>
#include <service/transaction.h>
#include <service/account.h>
#include <nlohmann/json.hpp>

namespace api {
    namespace transaction {
        void transaction_deposit(const httplib::Request& req, httplib::Response& res) {
            auto account_id = api::account::account_id(req);
            if (!account_id) {
                res.set_content("{\"error\": \"token is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto body = nlohmann::json::parse(req.body);
            auto amount = body["amount"];
            if (!amount.is_number_integer()) {
                res.set_content("{\"error\": \"amount is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto balance = service::transaction::deposit(account_id.value(), amount.get<int>());
            if (balance.has_value()) {
                res.set_content("{\"balance\": " + std::to_string(balance.value()) + "}", "application/json");
            } else {
                res.set_content("{\"error\": \"deposit failed\"}", "application/json");
                res.status = 400;
            }
        }

        void transaction_withdraw(const httplib::Request& req, httplib::Response& res) {
            auto account_id = api::account::account_id(req);
            if (!account_id.has_value()) {
                res.set_content("{\"error\": \"token is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto body = nlohmann::json::parse(req.body);
            auto amount = body["amount"];
            if (!amount.is_number_integer()) {
                res.set_content("{\"error\": \"amount is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto balance = service::transaction::withdraw(account_id.value(), amount.get<int>());
            if (balance.has_value()) {
                res.set_content("{\"balance\": " + std::to_string(balance.value()) + "}", "application/json");
            } else {
                res.set_content("{\"error\": \"withdraw failed\"}", "application/json");
                res.status = 400;
            }
        }

        void transaction_transfer(const httplib::Request& req, httplib::Response& res) {
            auto account_id = api::account::account_id(req);
            if (!account_id.has_value()) {
                res.set_content("{\"error\": \"token is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto body = nlohmann::json::parse(req.body);
            auto to_id = body["to_id"];
            if (!to_id.is_number_integer()) {
                res.set_content("{\"error\": \"to_id is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto amount = body["amount"];
            if (!amount.is_number_integer()) {
                res.set_content("{\"error\": \"amount is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto description = body["description"];
            if (!description.is_string()) {
                res.set_content("{\"error\": \"description is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto balance = service::transaction::transfer(account_id.value(), to_id.get<int>(), amount.get<int>(), description.get<std::string>());
            if (balance.has_value()) {
                res.set_content("{\"balance\": " + std::to_string(balance.value()) + "}", "application/json");
            } else {
                res.set_content("{\"error\": \"transfer failed\"}", "application/json");
                res.status = 400;
            }
        }
        
        void transaction_get_transactions(const httplib::Request& req, httplib::Response& res) {
            auto account_id = api::account::account_id(req);
            if (!account_id.has_value()) {
                res.set_content("{\"error\": \"token is invalid\"}", "application/json");
                res.status = 400;
                return;
            }
            auto transactions = service::transaction::get_transactions(account_id.value());
            std::vector<nlohmann::json> json_transactions;
            for (auto& transaction : transactions) {
                nlohmann::json json_transaction;
                json_transaction["id"] = transaction.id;
                json_transaction["from_account_id"] = transaction.from_account_id;
                json_transaction["to_account_id"] = transaction.to_account_id;
                json_transaction["amount"] = transaction.amount;
                json_transaction["description"] = transaction.description;
                json_transactions.push_back(json_transaction);
            }
            nlohmann::json json_response(json_transactions);
            res.set_content(json_response.dump(), "application/json");
        }
    }
}