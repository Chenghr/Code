#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int tag[100] = {0};//�������

        for(int i=0; i<s.size()-2; i++)
        {
            if(tag[i] == 0)//��һ����������ַ����������Ƿ����ظ��ַ�
            {
                tag[i] = -1;
                for(int j=i+1; j<s.size();j++)
                {
                    if(s[i] == s[j])
                    {
                        if(tag[i] == -1)//��һ���ҵ��ظ��ַ�
                        {
                            cout << s[i] << ":" << i ;
                            cout << "," << s[i] << ":" << j ;
                            tag[i] = 1;
                            tag[j] = 1;
                        }
                        else//���ǵ�һ���ҵ��ظ��ַ�
                        {
                            cout << "," << s[i] << ":" << j ;
                            tag[j] = 1;
                        }
                    }
                }
                if(tag[i] == 1)//tag��-1��Ϊ1��˵�������ҵ���һ���ظ��ַ�
                {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
