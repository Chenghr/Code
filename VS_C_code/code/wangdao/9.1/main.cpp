#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct STR
{
    string code;
    int deep;
    STR(string c,int d) : code(c),deep(d) {}
};

bool IsTarget(string s)//�ж�ĳ���ַ����Ƿ���2012
{
    string target = "2012";
    int j = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == target[j])
            j++;
        else
            j=0;
        if(j == 4)
            return true;
    }
    return false;
}

int bfs(STR s)
{
    queue <STR> q;
    map <string,int> maptest;//�����жϴ��Ƿ���ֹ�
    q.push(s);//ԭʼ�����
    maptest[s.code] = 1;

    while (!q.empty())
    {
        STR temp = q.front();
        q.pop();

        if(IsTarget(temp.code))
            return temp.deep;//�ҵ�Ŀ��״̬

        for(int i=0; i<temp.code.size()-1; i++)//���ν������¸�״̬
        {
            string a = temp.code;//����
            char ch = a[i];
            a[i] = a[i+1];
            a[i+1] = ch;

            if(maptest.find(a) == maptest.end())//��������´�û�г��ֹ�
            {
                maptest[a] = 1;
                q.push(STR(a,temp.deep+1));
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    string s;
    while (cin >> n)
    {
        cin >> s;
        cout << bfs(STR(s,0)) << endl;
    }
    return 0;
}
