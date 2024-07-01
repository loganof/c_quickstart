#include <memory>

int main(int argc, char const *argv[])
{
    // shared_ptr
    std::shared_ptr<int> ptr(new int(1));
    std::shared_ptr<int> ptr2 = std::make_shared<int>(new int(2));
    std::shared_ptr<int> ptr3 = ptr2;
    // unique_ptr
    std::unique_ptr<int> u_ptr(new int(1));
    std::unique_ptr<int> u_ptr2 = std::make_unique<int>(new int(2));
    // weak_ptr
    std::weak_ptr<int> w_ptr(ptr);
    return 0;
}
