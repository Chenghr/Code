#include <iostream>
#include <string>

using namespace std;

int keytab[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,
                    1,2,3,4,1,2,3,1,2,3,4};
//��������ַ�ͬ����һ����������ô��ĸ����ļ��������ǰ��������Ĳ
//��֮��������ȣ���ô��������ĸ�����ڲ�ͬ�İ���

int main()
{
    string s;
    while(cin >> s)
    {
        int time = 0;
        for(int i=0; i<s.size(); i++)
        {
            time += keytab[s[i]-'a'];//����ʱ��

            if(i != 0 && s[i]-s[i-1] == keytab[s[i]-'a']-keytab[s[i-1]-'a'])//�ж��Ƿ���Ҫ�ȴ�
            {
                time += 2;
            }
        }
        cout << time << endl;
    }
    return 0;
}
