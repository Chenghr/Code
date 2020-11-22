#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ip[1001];
string server[5001];
int n,m;
int tag[5001] = {1};

bool isdone()
{
    for(int i=0; i<m; i++)
    {
        if(tag[i] == 1) return false;
    }
    return true;
}

int getnum(string s)//��ǰip�ܷ��ʵ��������δ���ʹ��÷�������Ŀ
{
    int num = 0;
    int i=0;
    for(; i<m; i++)
    {
        if(tag[i] == 1) break;
    }
    for(; i<m; i++)
    {
        if(s == server[i]) return num;
        else
        {
            num++;
        }
    }
    return num;
}

bool comp(string x,string y)
{
    return getnum(x) > getnum(y);
}

int main()
{
    while (cin >> n)
    {
        cin.get();//�Ե���������Ļس�
        for(int i=0; i<n; i++)//����IP��ַ
        {
            getline(cin,ip[i]);
        }

        cin >> m;
        cin.get();//�Ե���������Ļس�
        for(int i=0; i<m; i++)//�����������ַ
        {
            getline(cin,server[i]);
            tag[i] = 1;//������鸳��ֵ
        }

        int flag = 1;//�ж��Ƿ��н�

        if(n == 1)//����ipֻ��һ�����ڷ�������ʱ���޽�
        {
            for(int i=0; i<m; i++)
            {
                if(ip[0] == server[i]) flag = 0;
            }
        }
        int j = 0;
        int num = 0;
        while (!isdone() && flag == 1)
        {
            sort(ip, ip+n, comp);//ip��ַ�����ظ�ʹ��
            for(; j<m; j++)
            {
                if(ip[0] == server[j]) break;
                else
                {
                    tag[j] = 0;
                }
            }
            num ++;
        }

        if(flag == 1) cout << num-1 << endl;//��һ��ʹ�÷����������л�
        else cout << -1 << endl;
    }
    return 0;
}
