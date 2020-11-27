#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strdiv(string s,int m)
{
    int cur = 0;
    for(int i=0; i<s.size(); i++)//模拟除法过程
    {
        int temp = cur*10+s[i]-'0';
        s[i] = temp/m+'0';
        cur = temp%m;

    }
    int pos = 0;
    if(s[pos] == '0')//找到s中第一个不为0的下标
    {
        pos++;
    }
    return s.substr(pos);//去除掉开始的0
}

string strexchange(string s,int m)
{
    string result;
    while(s.size() != 0)
    {
        int i = s.size()-1;
        int temp = (s[i]-'0')%m;//字符串取余等价于最后一位数取余(仅对于二进制)
        result += temp+'0';//存储结果
        s = strdiv(s,m);//字符串除法
    }
    reverse(result.begin(),result.end());//字符串逆序，保证输出正序
    return result;
}

int main()
{
    string s;
    while(cin >> s)
    {
        s = strexchange(s,2);
        cout << s << endl;
    }
    return 0;
}
