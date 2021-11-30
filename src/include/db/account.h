#pragma once
#include <optional>
#include <string>
#include <entity.h>

namespace db
{
    namespace account
    {
        int create_account(const std::string &first_name, const std::string &last_name, const std::string &phone, const std::string &password);
        std::optional<entity::BankAccount> get_account(int id);
        void update_account(const entity::BankAccount &account);
        void delete_account(int id);
    }
}