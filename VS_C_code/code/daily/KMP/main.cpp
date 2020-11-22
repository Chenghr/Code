#include <iostream>
#include <string>

using namespace std;

const int MAXN = 10000;
int next[MAXN];

void GetNextTable(string pattern)//创建next表，本质上使用pattern自己与自己匹配来获得next数组
{
    next[0] = -1;//初始化
    int k = -1, j = 0;

    while(j < pattern.size())//对每个子串求出其对应的next值
    {
        if(k == -1 || pattern[j] == pattern[i])
        {
            k ++;
            j ++;
            next[j] = k;
        }
        else
        {
            k = next[k];//next[i]是小于i的
        }
    }
}

int KMP(string test, string pattern)
{
    GetNextTable(pattern);
    int i = 0, j = 0;
    while(i < test.size() && j < pattern.size())
    {
        if(j == -1 || test[i] == pattern[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];//当前字符串匹配失败，移动模式串指针
        }
    }
    if(j == m) //匹配成功
    {
        return i-j+1;//返回第一个匹配串下标
    }
    else return -1;//匹配失败
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
