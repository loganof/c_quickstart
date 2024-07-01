// 4 kinds of templates
template <typename T>
class Data
{
public:
    static constexpr bool copyable = true;
};

template <typename T>
void log(T x)
{
}

template <typename T>
T zero = 0; // variable template(since c++14)

template <typename T>
bool dataCopyable = Data<T>::copyable;

template <typename T>
using DataList = Data<T *>; // alias template