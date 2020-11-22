#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long a_ten(string s,int a)
{
    long long n = 0;

    int pos = 0;//去除前导0
    if(s[pos] == '0') pos++;
    s = s.substr(pos);

    long long x = 1;
    for(int i=s.size()-1; i>=0; i--)
    {
        int temp;//字符转化为数字
        if(s[i] >= '0' && s[i] <= '9') temp = s[i]-'0';
        else if(s[i] >= 'a' && s[i] <= 'f') temp = s[i]-'a'+10;
        else temp = s[i]-'A'+10;

        n += x*temp;
        x = x*a;
    }
    return n;
}

string ten_b(long long n,int b)
{
    string result;
    while(n != 0)
    {
        int temp = n%b;
        n = n/b;

        char ch;//数字转化为字符
        if(temp >= 0 && temp <= 9) ch = temp+'0';
        else ch = 'A'+temp-10;

        result += ch;
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    string n;
    int a,b;
    while(cin >> a >> n >> b)
    {
        long long temp = a_ten(n,a);
        string result = ten_b(temp,b);
        cout << result << endl;
    }
    return 0;
}
