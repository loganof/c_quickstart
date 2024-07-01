#include <thread>

void do_background_work();
void f(int i, std::string const &s);

int main(int argc, char const *argv[])
{

    void some_function();
    void some_other_function();
    std::thread th1(some_function);
    std::thread th2 = std::move(th1);
    th1 = std::thread(some_other_function);
    std::thread th3;
    th3 = std::move(th2);
    th1 = std::move(th3);

    std::thread t(do_background_work);
    t.detach();
    assert(!t.joinable());
    std::thread t1(f, 3, "hello");

    return 0;
}

int f1(int x) throw();
int f11(int x) noexcept;
