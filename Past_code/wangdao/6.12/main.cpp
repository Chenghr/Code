#include <iostream>
#include <string>

using namespace std;

string stradd(string s1, string s2)
{
    string x = (s1.size() > s2.size()) ? s1 : s2;//x为较大的那个数
    string y = (s1.size() > s2.size()) ? s2 : s1;//y为较小的那个数

    int carry = 0;//进位
    int i = y.size()-1,j = x.size()-1;
    for(; i>=0; i--,j--)
    {
        int cur = carry+x[j]+y[i]-'0'-'0';
        x[j] = cur%10+'0';
        carry = cur/10;
    }
    while(carry != 0 && j >= 0)//仍有进位
    {
        int cur = carry+x[j]-'0';
        x[j] = cur%10+'0';
        carry = cur/10;
    }
    if(carry != 0)//x的最高位还要进一位
    {
        char ch = carry+'0';
        x = ch+x;
    }
    return x;
}

int main()
{
    int a,n;
    while(cin >> a >> n)
    {
        if(n == 1)//n == 1 时会有一个字符串为空，不好进行加法，直接特殊处理一下
        {
            cout << a << endl;
            continue;
        }

        char ch = a+'0';
        string result = "";
        result += ch;

        for(int i=2; i<=n; i++)
        {
            string temp;
            for(int j=0; j<i; j++)//构造加项
            {
                temp += ch;
            }

            result = stradd(temp,result);//进行字符串加法
        }

        cout << result << endl;
    }
    return 0;
}
