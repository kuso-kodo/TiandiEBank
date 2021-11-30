#include <db_storage.h>
#include <db/account.h>

namespace db
{
    namespace account
    {
        int create_account(const std::string &first_name, const std::string &last_name, const std::string &phone, const std::string &password)
        {
            entity::BankAccount account {-1, false, password, first_name, last_name, phone, 0};
            std::lock_guard<std::mutex> lock(db::storage_mutex);
            return db::storage.insert(account);
        }

        std::optional<entity::BankAccount> get_account(int id)
        {
            std::lock_guard<std::mutex> lock(db::storage_mutex);
            try {
                return db::storage.get<entity::BankAccount>(id);
            } catch (const std::exception &e) {
                return std::nullopt;
            }
        }

        void update_account(const entity::BankAccount &account) {
            std::lock_guard<std::mutex> lock(db::storage_mutex);
            db::storage.update(account);
        }

        void delete_account(int id) {
            std::optional<entity::BankAccount> account = get_account(id);
            if (account.has_value()) {
                auto t = account.value();
                t.deleted = true;
                update_account(t);
            }
        }
    }
}