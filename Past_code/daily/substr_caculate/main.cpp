//����һ����01��ɵ��ַ���������ÿ���Ӵ����ֵĴ���
//map�ײ�ʹ�ú����ʵ�ֵģ��ڲ���Ȼ�ὫԪ�ذ��չؼ�������

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        map<string,int> number;

        for(int i=0; i<=str.size(); i++)//i��Ϊ�Ӵ������±�
        {
            for(int j=0; j<i; j++)//jΪ�Ӵ���ʼ�±�
            {
                string key = str.substr(j,i-j);//��ȡ�Ӵ�
                number[key] ++;//�Ӵ����ִ���+1
            }
        }

        map<string,int> :: iterator it;//�������map�ĵ�����

        for(it = number.begin(); it != number.end(); it++)
        {
            if(it->second > 1)//���õ���������map��Ԫ��
            {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}
