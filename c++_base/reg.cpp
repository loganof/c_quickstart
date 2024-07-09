#include <stdio.h>
#include <string>
#include <regex>
#include <chrono>
#include <iostream>
#include <sstream>

int main()
{
    using namespace std::chrono;

    auto const search_func = [](std::string string_input) -> std::smatch
    {
        std::smatch matched;
        std::regex regex_for_usage{"used size: 0x([a-z0-9]+)"};
        if (std::regex_search(string_input, matched, regex_for_usage))
        {
            // 使用迭代器遍历, 这里的迭代器实际上是指向 std::sub_match 的指针
            for (auto iter = matched.begin(); iter != matched.end(); iter++)
            {
                std::cout << iter->length() << ": " << iter->str() << std::endl;
            }
            return matched;
        }
        return matched;
    };

    auto const hex_to_int = [](std::string str) -> int
    {
        unsigned int x;
        std::stringstream ss;
        ss << std::hex << str;
        ss >> x;
        return x;
    };

    auto file = fopen("./test.txt", "r");
    if (nullptr == file)
    {
        printf("open file failed!\n");
        return false;
    }
    char cma_line[256];
    while (NULL != fgets(cma_line, sizeof(cma_line), file))
    {
        std::cout << "cma_line: " << cma_line << std::endl;
        // auto start = high_resolution_clock::now();
        // 使用迭代器遍历, 这里的迭代器实际上是指向 std::sub_match 的指针
        // for (auto iter = matched.begin(); iter != matched.end(); iter++)
        // {
        //     std::cout << iter->length() << ": " << iter->str() << std::endl;
        // }
        // auto time = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
        // std::cout << "waste time: " << time << std::endl;
        // if (0 == strncmp(cma_line, "Total", 5))
        // {
        // }
        std::string str(cma_line);
        std::string::size_type idx = str.find("total");
        std::string ret1, ret2;
        int ret;
        if (idx != std::string::npos)
        {

            auto first = str.rfind("MB");
            auto second = str.rfind(" ");
            std::string ret = str.substr(second, first - second);
            auto used = std::stof(ret);
            std::cout << "firt: " << first << "second: " << second << "substr: " << used << std::endl;
            break;
        }

        // int n = 0;
        // if (n = str.find("total"))
        // {
        //     std::cout << "pos: " << n << std::endl;
        //     std::smatch matched = search_func(cma_line);
        //     if (!matched.empty())
        //     {
        //         auto used = hex_to_int(matched[1]) / (1024 * 1024);
        //         std::cout << "used: " << used << std::endl;
        //         break;
        //     }
        //     else
        //     {
        //         std::cout << "can't find!!!" << std::endl;
        //     }
        // }
    }
}