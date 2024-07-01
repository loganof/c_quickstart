class Collection
{
public:
    template <typename T>
    class Node
    {
    };

    template <typename T>
    T *alloc()
    {
    }

    template <typename T>
    static T zero = 0;

    template <typename T>
    using NodePtr = Node<T> *;
};
