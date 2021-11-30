#include <service/account.h>
#include <service/transaction.h>

#include <db/account.h>
#include <db/transaction.h>

namespace service {
    namespace transaction {
        std::optional<unsigned int> deposit_impl(int id, unsigned int amount) {
            std::optional<entity::BankAccount> account_opt = db::account::get_account(id);
            if (!account_opt.has_value()) {
                return std::nullopt;
            }
            auto account = account_opt.value();
            account.balance += amount;
            db::account::update_account(account);
            return account.balance;
        }

        std::optional<unsigned int> withdraw_impl(int id, unsigned int amount) {
            std::optional<entity::BankAccount> account_opt = db::account::get_account(id);
            if (!account_opt.has_value()) {
                return std::nullopt;
            }
            auto account = account_opt.value();
            if (account.balance < amount) {
                return std::nullopt;
            }
            account.balance -= amount;
            db::account::update_account(account); 
            return account.balance;
        }

        std::optional<unsigned int> deposit(int id, unsigned int amount) {
            auto result = deposit_impl(id, amount);
            if (result.has_value()) {
                db::transaction::create_transaction(1, id, amount, "deposit");
            }
            return result;
        }

        std::optional<unsigned int> withdraw(int id, unsigned int amount) {
            auto result = withdraw_impl(id, amount);
            if (result.has_value()) {
                db::transaction::create_transaction(id, 1, amount, "withdraw");
            }
            return result;
        }

        std::optional<unsigned int> transfer(int from_id, int to_id, unsigned int amount, const std::string &description) {
            std::optional<unsigned int> from_balance = withdraw_impl(from_id, amount);
            if (!from_balance.has_value()) {
                return std::nullopt;
            }
            std::optional<unsigned int> to_balance = deposit_impl(to_id, amount);
            if (!to_balance.has_value()) {
                withdraw_impl(from_id, amount);
                return std::nullopt;
            }
            db::transaction::create_transaction(from_id, to_id, amount, description);
            return from_balance.value();
        }

        std::vector<entity::BankAccountTransaction> get_transactions(int id) {
            return db::transaction::get_transactions_with(id);
        }
    }
}