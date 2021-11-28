#pragma once
#include <string>
#include <entity.h>

namespace db {
    namespace transaction {
        void create_transaction(int from_id, int to_id, unsigned int amount, const std::string &description);
        std::vector<entity::BankAccountTransaction> get_transactions_with(int id);
    }
}