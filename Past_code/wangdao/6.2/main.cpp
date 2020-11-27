#include <iostream>
#include <string>
#include <algorithm>//包含reverse函数

using namespace std;

string stradd(string s1,string s2,int m)//字符串本身是从低位到高位存储
{
    int cur = 0;//保存进位
    int i=0;
    for(; i<s2.size(); i++)
    {
        int temp = s1[i]+s2[i]+cur-'0'-'0';
        s1[i] = temp%m +'0';
        cur = temp/m;
    }
    while(cur != 0 && i<s1.size())
    {
        int temp = s1[i]+cur-'0';
        s1[i] = temp%m+'0';
        cur = temp/m;
        i++;
    }
    if(cur != 0)//超过s1的最高位，这里要在字符串末尾直接添加，不能赋值，会越界！
    {
        char ch = cur+'0';
        s1 += ch;
    }
    return s1;
}

int main()
{
    int m,a,b;
    while(cin >> m)
    {
        if(m == 0)
            break;
        cin >> a >> b;

        if(a == 0 && b == 0)//特殊情况，均为0时 s1 s2均为空串，输出为空
        {
            cout << "0" << endl;
            continue;
        }

        int temp;//保证a是较大的那个
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        string s1;
        string s2;
        while(a != 0)//先各自转化为二进制之后再相加
        {
            char ch =a%m+'0';
            s1 = s1+ch;
            a = a/m;
        }
        while(b != 0)
        {
            char ch = b%m+'0';
            s2 = s2+ch;
            b = b/m;
        }

        s1 = stradd(s1,s2,m);
        reverse(s1.begin(),s1.end());//反转字符串
        cout << s1 << endl;
    }
    return 0;
}
