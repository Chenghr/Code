#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int length;
int tag[7] = {0};//����ַ��Ƿ��Ѿ�ʹ��
char result[7] ;

void getresult(int pos)
{
    if(pos == length)//�������յ�
    {
        for(int i=0; i<length; i++)
        {
            cout << result[i];
        }
        cout << endl;
        return ;
    }
    for (int i=0; i<length; i++)//�����ֵ����С����������õ��ַ�
    {
        if(tag[i] == 0)//δ��ʹ�ù�
        {
            result[pos] = s[i];
            tag[i] = 1;
            getresult(pos+1);//����һ����λ��
            tag[i] = 0;//����
        }
    }
}

int main()
{
    while (cin >> s)
    {
        sort(s.begin(),s.end());//���ַ��������ֵ�������
        length = s.size();
        getresult(0);
        cout << endl;//ÿ��������������һ���س�
    }
    return 0;
}
