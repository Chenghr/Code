#include <iostream>
#include <string>
#include <vector>

using namespace std;

string strdiv(string s,int x)//字符串除法
{
    string result;
    int remainder = 0;
    for(int i=0; i<s.size(); i++)
    {
        int cur = s[i]-'0'+10*remainder;
        char ch = cur/x+'0';
        result += ch;
        remainder = cur%x;
    }

    int pos = 0;
    while(result[pos] == '0') pos++;
    return result.substr(pos);
}

string strmul(string s, int x)
{
    string result;
    int carry = 0;
    for(int i=s.size()-1; i>=0; i--)
    {
        int cur = carry+(s[i]-'0')*x;
        carry = cur/10;
        char ch = (cur%10)+'0';
        result = ch+result;
    }
    if(carry != 0)
    {
        char ch = carry+'0';
        result = ch+result;//这里是加，不是赋值！
    }
    return result;
}

string stradd(string s,int x)
{
    int carry = x;
    for(int i=s.size()-1; i>=0; i--)
    {
        int cur = carry+s[i]-'0';
        s[i] = cur%10+'0';
        carry = cur/10;
    }
    if(carry != 0)
    {
        char ch = carry+'0';
        s = ch+s;
    }
    return s;
}

string ten_two(string s)//十进制字符串转化为二进制字符串
{
    string result;
    while(s.size() != 0)
    {
        int temp = s[s.size()-1]-'0';
        temp = temp%2;
        char ch = temp+'0';
        result += ch;//逆序存储

        s = strdiv(s,2);
    }
    return result;
}

string two_ten(string s)//从高位到低位以及加上各数位的值，并不断乘以2即可
{
    string result = "0";
    for(int i=0; i<s.size(); i++)
    {
        result = strmul(result,2);
        int temp = s[i]-'0';
        result = stradd(result,temp);
    }
    return result;
}

int main()
{
    string s;
    while(cin >> s)
    {
        string temp = ten_two(s);
        string answer = two_ten(temp);
        cout << answer << endl;
    }
    return 0;
}
