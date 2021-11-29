#pragma once
#include <optional>
#include <string>
#include <vector>
#include <entity.h>

namespace service
{
    namespace transaction
    {
        std::optional<unsigned int> deposit(int id, unsigned int amount);
        std::optional<unsigned int> withdraw(int id, unsigned int amount);
        std::optional<unsigned int> transfer(int from_id, int to_id, unsigned int amount, const std::string &description);
        std::vector<entity::BankAccountTransaction> get_transactions(int id);
    }
}