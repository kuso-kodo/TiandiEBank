#include <db_storage.h>
#include <db/db.h>

namespace db {
    Storage storage = storage_schema();
    std::mutex storage_mutex;

    void init_storage() {
        storage_mutex.lock();
        storage.sync_schema(true);
        entity::BankAccount account {-1, false, "1145141919810", "", "", "", 0};
        storage.insert(account);
        storage_mutex.unlock();
    }
}
