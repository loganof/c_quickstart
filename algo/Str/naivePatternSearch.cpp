#include <string>
// 朴素的模式匹配
int dex(std::string S, std::string T)
{
    int len_S = S.size();
    int len_T = T.size();

    int i = 0;
    int j = 0;

    while (i < len_S && j < len_T)
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 0;
        }
    }
    if (j == len_T)
    {
        return i - len_T;
    }
    else
    {
        return 0;
    }
}

// caculate next array
void get_next(std::string T, int *next)
{
    int i = 1, j = 0;
    int len = T.size();
    next[0] = 0;
    while (i < len)
    {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int index_KMP(std::string S, std::string T)
{
    int i = 0, j = 1;
}

int main(int argc, char const *argv[])
{
    std::string S = "goodgoogle";
    std::string T = "google";
    int index = dex(S, T);
    printf("index: %d\n", index);
    return 0;
}
