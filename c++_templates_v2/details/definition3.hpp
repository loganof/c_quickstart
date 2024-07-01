template <typename T>
class List
{
public:
    List() = default;

    template <typename U>
    class Handle; // member class template

    template <typename U>
    List(List<U> const &); // member function template

    template <typename U>
    static U zero; // member variable template(since c++14)
};

template <typename T>
template <typename U>
class List<T>::Handle
{
};

template <typename T>
template <typename U>
List<T>::List(List<U> const &b)
{
}

template <typename T>
template <typename U>
U List<T>::zero = 0;