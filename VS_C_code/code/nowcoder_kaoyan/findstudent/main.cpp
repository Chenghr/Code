#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,string> student;//��ѧ����Ϊkey����Ϣ��Ϊvalue

int main()
{
    int n;
    cin >> n;
    cin.get();//�Ե��س�

    for(int i=0; i<n; i++)
    {
        string s;
        getline(cin,s);//ע�Ȿ��������ʽ��������һ���ַ�������������Ϣ��

        int pos = 0;
        for(pos=0; pos<s.size(); pos++)//�ҵ���һ���ո�
        {
            if(s[pos] == ' ') break;
        }
        string num = s.substr(0,pos);//��ȡѧ��
        student[num] = s;//ѧ����Ϊkey���洢value
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        string num;
        cin >> num;
        string s = student[num];
        if(s == "")//����ʧ��
        {
            cout << "No Answer!" << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}
