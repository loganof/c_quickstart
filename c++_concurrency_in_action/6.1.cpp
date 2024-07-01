#include <utility>
#include <iostream>

class X {

};

void g(X& ) {
    std::cout << "g() for variable\n";
}

void g (X const&) {
    std::cout << "g() for constant\n";
}

void g (X&&) {
    std::cout << "g() for movable object\n";
}

void f (X& val) {
    g(val);
}

void f (X const& val) {
    g(val);
}

void f (X&& val) {
    g(std::move(val));
}

template <typename T>
void f (T val) {
    g(T);
}

template <typename T>
void f (T&& val) {
    g(std::forward<T>(val));
}

int main(int argc, char const *argv[])
{
    /* code */
    X v;
    X const c;
    
    f(v);
    f(c);
    f(X());
    f(std::move(v));
    return 0;
}
