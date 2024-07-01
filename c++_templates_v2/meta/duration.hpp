#include "ratio.hpp"

// duration type for values of type T with unit type U:
template <typename T, typename U = Ratio<1>>
class Duration
{
public:
    using ValueType = T;
    using UnitType = typename U::Type;

private:
    ValueType val;

public:
    constexpr Duration(ValueType v = 0) : val(v) {}
    // 函数后面const的作用：一种保证，保证这个成员函数不会改变对象的状态，该函数为“只读函数”
    // 非成员函数或静态成员函数后面加const，会产生编译错误
    // 隐式表示，传入的this指针为const指针
    // const 成员函数能够被const及非const对象调用，但非const成员函数不能被const对象调用
    constexpr ValueType value() const
    {
        return val;
    }
};
