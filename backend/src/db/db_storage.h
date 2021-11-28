#pragma once
#include <sqlite_orm.h>
#include <entity.h>
#include <mutex>

namespace db
{
    auto storage_schema()
    {
        auto account_table = sqlite_orm::make_table("account",
                                                    sqlite_orm::make_column("id", &entity::BankAccount::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                    sqlite_orm::make_column("deleted", &entity::BankAccount::deleted),
                                                    sqlite_orm::make_column("password", &entity::BankAccount::password),
                                                    sqlite_orm::make_column("first_name", &entity::BankAccount::first_name),
                                                    sqlite_orm::make_column("last_name", &entity::BankAccount::last_name),
                                                    sqlite_orm::make_column("phone", &entity::BankAccount::phone),
                                                    sqlite_orm::make_column("balance", &entity::BankAccount::balance));
        auto transcation_table = sqlite_orm::make_table("transaction",
                                                        sqlite_orm::make_column("id", &entity::BankAccountTransaction::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                        sqlite_orm::make_column("from_account_id", &entity::BankAccountTransaction::from_account_id),
                                                        sqlite_orm::make_column("to_account_id", &entity::BankAccountTransaction::to_account_id),
                                                        sqlite_orm::make_column("amount", &entity::BankAccountTransaction::amount),
                                                        sqlite_orm::make_column("description", &entity::BankAccountTransaction::description));
        return sqlite_orm::make_storage("bank.db", account_table, transcation_table);
    }
    using Storage = decltype(storage_schema());

    extern Storage storage;
    extern std::mutex storage_mutex;
}
