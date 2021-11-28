#pragma once
#include <optional>
#include <string>
#include <entity.h>

namespace service
{
    namespace transaction
    {
        void deposit(int id, unsigned int amount);
        void withdraw(int id, unsigned int amount);
        void transfer(int from_id, int to_id, unsigned int amount);
        std::vector<entity::Transaction> get_transactions(int id);
    }
}