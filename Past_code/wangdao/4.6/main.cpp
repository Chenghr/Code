#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool isequal(char c1,char c2)
{
    if(tolower(c1) == tolower(c2))//将c1、c2均转化为小写字母形式
    {
        return true;
    }
    return false;
}

bool mulequal(char ch,string p,int& j)
{
    int i = j+1;
    while(i < p.size())
    {
        if(p[i] == ']')
        {
            break;
        }
        else i++;
    }
    int t = j+1;
    j = i;//令j指向']'

    for(; t<i; t++)
    {
        if(isalpha(p[t]))//字母
        {
            if(isequal(ch,p[t]))
            {
                return true;
            }
        }
        else if(ch == p[t])//其他符号
        {
            return true;
        }
    }
    return false;
}

bool strcomp(string t,string p)
{
    int i = 0, j = 0;
    while(i < t.size() && j < p.size())
    {
        if(isalpha(p[j]))//字母
        {
            if(isequal(t[i],p[j]))
            {
                i++;
                j++;
                continue;
            }
            else return false;
        }
        else if(p[j] == '[')//当前j指向'['
        {
            if(mulequal(t[i],p,j))
            {
                i ++;
                j ++;//函数内j指向']'
                continue;
            }
            else return false;
        }
        else//常规字符
        {
            if(t[i] == p[j])
            {
                i++;
                j++;
                continue;
            }
            else return false;
        }
    }
    if(i == t.size() && j == p.size()) return true;//两个字符串同时匹配到终点才算成功
    return false;
}

int main()
{
    vector<string> test;
    string pattern;
    int n;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        test.push_back(s);
    }
    cin >> pattern;

    for(int i=0; i<n; i++)
    {
        string temp = test[i];
        if(strcomp(temp,pattern))
        {
            cout << i+1 << " " << temp << endl;
        }
    }
    return 0;
}
