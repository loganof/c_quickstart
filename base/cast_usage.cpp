

class Parents
{
private:
    /* data */
public:
    Parents(/* args */);
    ~Parents();
};

Parents::Parents(/* args */)
{
}

Parents::~Parents()
{
}

class Person : public Parents
{
public:
    Person() {}
    ~Person() {}
};

int main(int argc, char const *argv[])
{
    // static_cast
    double *ptr1 = new double(1);
    double *ptr2 = static_cast<double *>(ptr1);

    const int a = 3;
    const int *ptr = &a;
    // const_cast
    auto b = const_cast<int *>(ptr);
    // dynamic_cast, 用于类的上下形转换
    Parents *parent = new Parents();
    Person *son = new Person();
    Parents *parent2 = dynamic_cast<Parents *>(son);
    // reinterpret_cast
    auto c = reinterpret_cast<int *>(ptr1);
    return 0;
}
