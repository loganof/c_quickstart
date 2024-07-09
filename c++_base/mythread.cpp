// #include <thread>
#include <future>

void f();
int main(int argc, char const *argv[])
{

    auto fut1 = std::async(f);
    auto fut2 = std::async(std::launch::async | std::launch::deferred, f);
    using FilterContainer = std::vector<std::function<bool(int)>>;
    FilterContainer filters;

    return 0;
}
