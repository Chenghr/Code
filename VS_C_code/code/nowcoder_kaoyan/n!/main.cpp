#include <iostream>
#include <string>

using namespace std;
const int MAXN = 1001;
string result[MAXN];

string strmul(string x,string y)//字符串乘法
{
    string answer;
    int a[100000] = {0};//存储结果

    int carry = 0;
    for(int i=x.size()-1; i>=0; i--)
    {
        for(int j=y.size()-1; j>=0; j--)
        {
            a[i+j+1] += (x[i]-'0')*(y[j]-'0');//a[0]留出来防止产生进位
        }
    }

    for(int i=x.size()+y.size()-1; i>=1; i--)
    {
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }

    int i = 0;
    while(a[i] == 0)
    {
        i++;
    }
    for(; i<=x.size()+y.size()-1; i++)
    {
        char ch = a[i]+'0';
        answer += ch;
    }
    return answer;
}

void initial()
{
    result[0] = "1";
    result[1] = "1";
    for(int i = 2; i<MAXN; i++)
    {
        string temp;
        int j = i;
        while(j != 0)
        {
            char ch = j%10+'0';
            temp = ch+temp;
            j /=10;
        }
        result[i] = strmul(result[i-1],temp);
    }
}

int main()
{
    initial();
    int n;
    while(cin >> n)
    {
        cout << result[n] << endl;
    }
    return 0;
}
