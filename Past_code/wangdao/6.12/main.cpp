#include <iostream>
#include <string>

using namespace std;

string stradd(string s1, string s2)
{
    string x = (s1.size() > s2.size()) ? s1 : s2;//xΪ�ϴ���Ǹ���
    string y = (s1.size() > s2.size()) ? s2 : s1;//yΪ��С���Ǹ���

    int carry = 0;//��λ
    int i = y.size()-1,j = x.size()-1;
    for(; i>=0; i--,j--)
    {
        int cur = carry+x[j]+y[i]-'0'-'0';
        x[j] = cur%10+'0';
        carry = cur/10;
    }
    while(carry != 0 && j >= 0)//���н�λ
    {
        int cur = carry+x[j]-'0';
        x[j] = cur%10+'0';
        carry = cur/10;
    }
    if(carry != 0)//x�����λ��Ҫ��һλ
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
        if(n == 1)//n == 1 ʱ����һ���ַ���Ϊ�գ����ý��мӷ���ֱ�����⴦��һ��
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
            for(int j=0; j<i; j++)//�������
            {
                temp += ch;
            }

            result = stradd(temp,result);//�����ַ����ӷ�
        }

        cout << result << endl;
    }
    return 0;
}
