#include <iostream>
#include <string>
#include <algorithm>//����reverse����

using namespace std;

string stradd(string s1,string s2,int m)//�ַ��������Ǵӵ�λ����λ�洢
{
    int cur = 0;//�����λ
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
    if(cur != 0)//����s1�����λ������Ҫ���ַ���ĩβֱ����ӣ����ܸ�ֵ����Խ�磡
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

        if(a == 0 && b == 0)//�����������Ϊ0ʱ s1 s2��Ϊ�մ������Ϊ��
        {
            cout << "0" << endl;
            continue;
        }

        int temp;//��֤a�ǽϴ���Ǹ�
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        string s1;
        string s2;
        while(a != 0)//�ȸ���ת��Ϊ������֮�������
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
        reverse(s1.begin(),s1.end());//��ת�ַ���
        cout << s1 << endl;
    }
    return 0;
}
