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
        s += '$';//��־����Ľ���
        op.push('#');//�ַ�ջ��ռ��
        int index = 0;//�ַ����±�

        while (index < s.size())
        {
            if(isdigit(s[index]))//��������ת������ѹջ
            {
                int temp = getnum(s,index);//getnum������˶�index������
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
                    double y = num.top();//������������վ��������ȡ
                    num.pop();
                    double x = num.top();
                    num.pop();
                    char ch = op.top();
                    op.pop();

                    double result = caculate(x,y,ch);
                    num.push(result);//������ѹջ,��ʱ�������ѹջ����Ϊ֮ǰ�Ŀ��ܻ�û������
                }
            }

        }
        printf("%.0lf\n",num.top());
    }
    return 0;
}
