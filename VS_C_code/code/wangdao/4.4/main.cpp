//总的来说两种思路，一是先进行浮点数对齐，对齐之后进行同一加法；
//另一种是分为整数和小数两部分，分别进行加法

#include <iostream>
#include <string>

using namespace std;

string stradd_1(string s1,string s2)//浮点数对齐后相加
{
    string result,sa,sb;

    //浮点数对齐
    int ia = s1.find(".");
    int ib = s2.find(".");
    sa = (ia > ib) ? s1 : s2;//s1、s2中整数部分较长的赋值给sa，另一个给sb
    sb = (ia > ib) ? s2 : s1;

    int n = (ia > ib) ? (ia - ib) : (ib - ia);//整数部分对齐
    while (n--)
    {
        sb = "0"+sb;
    }
    s1 = sa;
    s2 = sb;

    sa = (s1.size() > s2.size()) ? s1 : s2;//s1、s2中小数部分较长的赋值给sa，另一个给sb
    sb = (s1.size() > s2.size()) ? s2 : s1;
    n = (s1.size() > s2.size()) ? (s1.size() - s2.size()) : (s2.size() - s1.size());//小数部分对齐
    while (n--)
    {
        sb += "0";
    }
    s1 = sa;
    s2 = sb;

    //对齐后的浮点数相加
    int carry = 0;//进位
    for(int i=s1.size()-1; i>=0; i--)
    {
        if(s1[i] == '.')
        {
            result = "."+result;
            continue;
        }
        char value = s1[i]-'0'+s2[i]-'0'+carry;
        result = char(value%10 + '0')+result;//存储当前位的结果
        carry = value/10;//存储进位
    }
    while (carry != 0)//对最高位产生的进位进行处理
    {
        result = char(carry%10 + '0')+result;
        carry = carry/10;
    }
    return result;
}

void stradd_2(string s1,string s2)
{
    string z1,x1,z2,x2;

    //先进行整数与小数的分割
    int ia = s1.find(".");
    int ib = s2.find(".");
    z1 = (ia > ib) ? s1.substr(0,ia) : s2.substr(0,ib);//保证整数部分z1最长,ia返回为'.'的下标，数组中下标比实际-1，故恰好为整数部分长度
    z2 = (ia > ib) ? s2.substr(0,ib) : s1.substr(0,ia);
    x1 = (s1.size()-ia > s2.size() -ib) ? s1.substr(ia+1,s1.size()-ia) : s2.substr(ib+1,s2.size()-ib);//保证小数部分x1最长
    x2 = (s1.size()-ia > s2.size() -ib) ? s2.substr(ib+1,s2.size()-ib) : s1.substr(ia+1,s1.size()-ia);

    //分别进行加法
    int carry = 0;//进位
    for(int i=x2.size()-1; i>=0; i--)//先进行小数部分加法
    {
        int a = x1[i]-'0'+x2[i]-'0'+carry;
        x1[i] = a%10+'0';
        carry = a/10;
    }

    int l = z1.size()-1;
    for(int i=z2.size()-1; i>=0; i--,l--)
    {
        int a = z1[l]-'0'+z2[i]-'0'+carry;
        z1[l] = a%10+'0';
        carry = a/10;
    }
    while(l >= 0)
    {
        int a = z1[l]-'0'+carry;
        z1[l] = a%10+'0';
        carry = a/10;
        l--;
    }
    while (carry != 0)
    {
        z1 = char (carry%10+'0')+z1;
        carry = carry/10;
    }
    cout << z1 << "." << x1 << endl;
    return ;
}

int main()
{
    string s1,s2;
    while (cin >> s1 >> s2)
    {
        cout << stradd_1(s1,s2) << endl;
        stradd_2(s1,s2);
    }
    return 0;
}
