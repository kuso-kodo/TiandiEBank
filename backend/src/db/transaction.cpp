#include <db_storage.h>
#include <db/transaction.h>

namespace db
{
    namespace transaction
    {
        void create_transaction(int from_id, int to_id, unsigned int amount, const std::string &description)
        {
            entity::BankAccountTransaction transaction{-1, from_id, to_id, amount, description};
            std::lock_guard<std::mutex> lock(db::storage_mutex);
            db::storage.insert(transaction);
        }

        std::vector<entity::BankAccountTransaction> get_transactions_with(int id)
        {
            std::lock_guard<std::mutex> lock(db::storage_mutex);
            using namespace sqlite_orm;
            return db::storage.get_all<entity::BankAccountTransaction>(where(
                c(&entity::BankAccountTransaction::from_account_id) == id or 
                c(&entity::BankAccountTransaction::from_account_id) == 1 or 
                c(&entity::BankAccountTransaction::to_account_id) == id or 
                c(&entity::BankAccountTransaction::to_account_id) == 1), 
                order_by(&entity::BankAccountTransaction::id).desc());
        }
    }
}