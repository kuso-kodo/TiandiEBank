#include <db_storage.h>
#include <db/db.h>

namespace db {
    Storage storage = storage_schema();
    std::mutex storage_mutex;

    void init_storage() {
        storage_mutex.lock();
        storage.sync_schema(true);
        storage_mutex.unlock();
    }
}
