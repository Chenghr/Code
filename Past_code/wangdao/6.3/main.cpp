#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strdiv(string s,int m)
{
    int cur = 0;
    for(int i=0; i<s.size(); i++)//ģ���������
    {
        int temp = cur*10+s[i]-'0';
        s[i] = temp/m+'0';
        cur = temp%m;

    }
    int pos = 0;
    if(s[pos] == '0')//�ҵ�s�е�һ����Ϊ0���±�
    {
        pos++;
    }
    return s.substr(pos);//ȥ������ʼ��0
}

string strexchange(string s,int m)
{
    string result;
    while(s.size() != 0)
    {
        int i = s.size()-1;
        int temp = (s[i]-'0')%m;//�ַ���ȡ��ȼ������һλ��ȡ��(�����ڶ�����)
        result += temp+'0';//�洢���
        s = strdiv(s,m);//�ַ�������
    }
    reverse(result.begin(),result.end());//�ַ������򣬱�֤�������
    return result;
}

int main()
{
    string s;
    while(cin >> s)
    {
        s = strexchange(s,2);
        cout << s << endl;
    }
    return 0;
}
