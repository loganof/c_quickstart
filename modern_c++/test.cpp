// #include <memory>

// class Investment
// {
// };

// auto delInvmt = [](Investment *pInvestment)
// {
//     makeLogEntry(pInvestment);
//     delete pInvestment;
// };

// template <typename... Ts>
// std::unique_ptr<Investment, decltype(delInvmt)>
// makeInvestment(Ts &&...param)
// {
//     std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);
// }
// class Widget
// {
// };

// // make_unique在c++14才出现，c++11时可手动实现，如下所示
// template <typename T, typename... Ts>
// std::unique_ptr<T> make_unique(Ts &&...params)
// {
//     return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
// }

// int main(int argc, char const *argv[])
// {

//     auto spw = std::make_shared<Widget>();
//     std::weak_ptr<Widget> wpw(spw);

//     return 0;
// }

// #include <type_traits>

// template <typename T>
// typename remove_reference<T>::type &&
// move(T &&param)
// {
//     using ReturnType = typename remove_reference<T>::type &&;

//     return static_cast<ReturnType>(param);
// }

// template <typename T>
// decltype(auto) move(T &&param)
// {
//     using ReturnType = remove_reference_t<T> &&;
//     return static_cast<ReturnType>(param);
// }

// // 左值引用 T&， 右值引用T&&
// void f(Widget &&param);
// Widget &&var1 = Widget();
// auto &&var2 = var1;

// template <typename T>
// void f(std::vector<T> &&param);

// template <typename T>
// void f(T &&param);

// auto timeFuncInvocation = [](auto &&func, auto &&...params)
// {
//     // start timer;
//     std::forward<func>(func)(std::forward < decltype(params)(params)...);
// };

// typedef AbstractFactory<Window, Button, ScrollBar> WidgetFactory;

// template <class T>
// T *MakeReWidget(WidgetFactory &factory)
// {
//     T &pW = factory.Create<T>();
//     pW->SetColor(RED);
//     return pW;
// }

// class NullType
// {
// };

// struct EmptyType
// {
// };

// template <class TList, class T>
// struct Erase;

// template <class T>
// struct Erase<NullType, T>
// {
//     typedef NullType Result;
// };

// template <class T, class Tail>
// struct Erase<Typelist<T, Tail>, T>
// {
//     typedef Tail Result;
// };

#include <map>
#include <string>
#include <iostream>
// using namespace std;
#include <stdio.h>
std::map<std::string, std::string> mp;

std::vector<std::string> splitByVerticalLine(std::string &str){
    std::vector<std::string> ret;
    int index = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '|')
        {
            ret.push_back(str.substr(index, i));
            index = i;
        }
    }
    index++;
    ret.push_back(str.substr(index, str.length()));
    return ret;
}

std::vector<std::vector<std::string>> splitBySpace(std::vector<std::string> & vec){
    std::vector<std::vector<std::string>> ret;
    std::vector<std::string> temp;
    for (auto &item : vec)
    {
        int index = 0;
        for (size_t i = 0; i < item.length(); i++)
        {
            if(item[i] == ' '){
                temp.push_back(item.substr(index, i));
                index = i + 1;
            }
        }
        temp.push_back(item.substr(index, item.length()));
        ret.push_back(temp);
    }
    return ret;
}

std::string decode(std::string &str){
    std::string ret="";
    for (int i = 0; i < str.length(); i++)
    {
        // 遍历mp
        for(const auto &x : mp){    // 使用范围for循环
            if(str[i] == x.second[0]){
                return x.first;
            }
        }
        return " ";
    }
}

int main(int argc, char const *argv[])
{
    std::string decodedData{"-. -.. -... -... --..|--. --.. --... --...."};
    std::vector<std::string> splitData = splitByVerticalLine(decodedData);
    for (auto &x : splitData)
    {
        std::cout << x << std::endl;
    } 
    auto splitDataBySpace = splitBySpace(splitData);  
    for(auto &x : splitDataBySpace){ 
        for(auto &y : x) 
        std::cout << y << "\n"; 
    }
    // std::cout << decode(splitDataBySpace[0][0]) << std::endl;
    // mp.insert(std::pair<std::string, std::string>("a", "-."));
    // mp.insert(std::pair<std::string, std::string>("b", "-.."));
    // mp.insert(std::pair<std::string, std::string>("c", "-..."));
    // printf(mp.begin()->second.c_str()); 
    return 0;
}

