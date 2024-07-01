#include <mutex>
#include "9_9_interruptible_thread.hpp"

std::mutex config_mutex;
std::vector<interruptible_thread> background_threads;
void background_thread(int disk_id)
{
    while (true)
    {
        interruption_point();
        fs_change fsc = get_fs_changes(disk_id);
        if (fsc.has_changeds())
        {
            update_index(fsc);
        }
    }
}
