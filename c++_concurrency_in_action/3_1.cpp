// Protecting a list with a mutex
#include <list>
#include <mutex>
#include <algorithm>

std::mutex mut;
std::list<int> some_list;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(mut);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(mut);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}