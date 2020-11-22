#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

int prior(char ch)
{
    if(ch == '#')
    {
        return 0;
    }
    else if(ch == '$')
    {
        return 1;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else if(ch == '*' || ch == '/')
    {
        return 3;
    }
    return 0;
}

double caculate(double x, double y, char c)
{
    if(c == '+') return x+y;
    else if(c == '-') return x-y;
    else if(c == '*') return x*y;
    else return x/y;
    return 0;
}

double getnum(string s, int &index)
{
    double temp = 0;
    while(isdigit(s[index]))
    {
        temp = temp*10+s[index]-'0';
        index++;
    }
    return temp;
}

int main()
{
    string s;

    while(cin >> s)
    {
        stack <double> num;
        stack <char> op;
        s += '$';//标志计算的结束
        op.push('#');//字符栈的占用
        int index = 0;//字符串下标

        while (index < s.size())
        {
            if(isdigit(s[index]))//进行数字转化并且压栈
            {
                int temp = getnum(s,index);//getnum中完成了对index的自增
                num.push(temp);
            }
            else
            {
                if(prior(s[index]) > prior(op.top()))
                {
                    op.push(s[index]);
                    index ++;
                }
                else
                {
                    double y = num.top();//被运算数后入站，所以先取
                    num.pop();
                    double x = num.top();
                    num.pop();
                    char ch = op.top();
                    op.pop();

                    double result = caculate(x,y,ch);
                    num.push(result);//运算结果压栈,此时运算符不压栈，因为之前的可能还没运算完
                }
            }

        }
        printf("%.0lf\n",num.top());
    }
    return 0;
}
