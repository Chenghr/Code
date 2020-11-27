#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct person
{
    string father;
    int sonnum;
    int self;//����ӵ�е�ͨ����
    int sum;//���ڰ�������Ϊ�׵�ͨ����
};

map<string,person> m; //���������ַ�����ṹ���Ӧ����

string findroot(string x)//���Ҹ��ڵ�
{
    string root = x;
    while(x != m[x].father)//�ҵ���Ӧ�ĸ����
    {
        x = m[x].father;
    }
    if(root != x)//��Ϊ����ͨͼʱ
    {
        m[root].father = x;//·��ѹ��
    }
    return x;
}

void Union(string x, string y, int t)//�ϲ�����
{
    string a = findroot(x);//�ҵ����Եĸ������map�е��±�
    string b = findroot(y);
    string i;
    string j;
    string l;
    if(a != b)//����һ��������
    {
        i = (m[a].self >= m[b].self) ? a : b;//iΪx��y�ĸ����������ͨ�����ϴ��ߣ�jΪ��С��
        j = (m[a].self >= m[b].self) ? b : a;

        m[j].father = i;//��ͨ������С����ӵ�ͨ�����ϴ��
        m[i].sonnum += m[j].sonnum;//���°�������
        m[i].sum = m[i].sum + m[j].sum + t;//�����ܵ�ͨ����

        l = (m[x].self >= m[y].self) ? x : y;//l Ϊx��y������ͨ�����ϴ���Ǹ�
        if(m[l].self > m[i].self)//����������ͨ���������Ǹ��˲��ܳ�ΪͷĿ
        {
            m[i].father = l;
            m[l].father = l;
            m[l].sonnum = m[i].sonnum;
            m[l].sum = m[i].sum;
        }
    }
    else
    {
        m[a].sum += t;//�����ϴ�����ͨ����

        l = (m[x].self >= m[y].self) ? x : y;//l Ϊx��y������ͨ�����ϴ���Ǹ�
        if(m[l].self > m[i].self)//����������ͨ���������Ǹ��˲��ܳ�ΪͷĿ
        {
            m[i].father = l;
            m[l].father = l;
            m[l].sonnum = m[i].sonnum;
            m[l].sum = m[i].sum;
        }
    }

    return ;
}

int main()
{
    int n,k;
    while (cin >> n >> k)
    {
        m.clear();//��ʼ��map

        string s1,s2;
        int t;

        for(int i=0; i<n; i++)//������Ϣ�Լ���ʼ��
        {
            cin >> s1 >> s2 >> t;

            if(m.find(s1) == m.end())//map��û�д洢��s1
            {
                person temp;
                temp.father = s1;
                temp.sonnum = 1;
                temp.self = t;
                temp.sum = 0;//��ͨ�������ںϲ���ʱ����׷�ӵ������
            }
            else
            {
                m[s1].self += t;
            }

            if(m.find(s2) == m.end())//map��û�д洢��s2
            {
                person temp;
                temp.father = s2;
                temp.sonnum = 1;
                temp.self = t;
                temp.sum = 0;//��ͨ�������ںϲ���ʱ����׷�ӵ������
            }
            else
            {
                m[s2].self += t;
            }

            Union(s1,s2,t);
        }

        int num = 0;//�ڰ���Ŀ
        vector<string> head;//�洢�ڰ�ͷĿ������

        for(map<string,person>::iterator it = m.begin(); it != m.end(); it++)//�������������
        {
            if(it->second.father == it->first && it->second.sum > k && it->second.sonnum > 2)
            {
                head.push_back(it->first);//�洢���������ĺڰ�ͷĿ
                num ++;
            }
        }

        sort(head.begin(),head.end());//ͷĿ���ְ����ֵ�������

        cout << num << endl;//���
        for(int i=0; i<head.size(); i++)
        {
            cout << head[i] << " " << m[head[i]].sonnum << endl;
        }

    }
    return 0;
}
