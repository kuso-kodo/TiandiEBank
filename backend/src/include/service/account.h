#pragma once
#include <optional>
#include <string>
#include <entity.h>

namespace service
{
    namespace account
    {
        int create_account(const std::string &first_name, const std::string &last_name, const std::string &phone, const std::string &password);
        std::optional<std::string> login_account(int id, const std::string &password);
        std::optional<entity::BankAccount> get_account(int id);
        std::optional<int> extract_id(const std::string &token);
        std::optional<std::string> update_account_info(int id, const std::optional<std::string> &first_name, const std::optional<std::string> &last_name, const std::optional<std::string> &phone, const std::optional<std::string> &password);
        void delete_account(int id);
    }
}