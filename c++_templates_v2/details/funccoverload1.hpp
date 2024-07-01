#ifndef FUNCCOVERLOAD1
#define FUNCCOVERLOAD1

template <typename T>
int f(T)
{
    return 1;
}

template <typename T>
int f(T *)
{
    return 2;
}

#endif