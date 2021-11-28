#pragma once
#include <string>
namespace entity {
    struct BankAccount {
        int id;
        bool deleted;
        std::string password;
        std::string first_name;
        std::string last_name;
        std::string phone;
        unsigned int balance;
    };

    struct BankAccountTransaction {
        int id;
        int from_account_id;
        int to_account_id;
        unsigned int amount;
        std::string description;
    };
}
