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
    int self;//自身拥有的通信量
    int sum;//所在帮派以其为首的通信量
};

map<string,person> m; //将人名的字符串与结构体对应起来

string findroot(string x)//查找根节点
{
    string root = x;
    while(x != m[x].father)//找到对应的根结点
    {
        x = m[x].father;
    }
    if(root != x)//不为单连通图时
    {
        m[root].father = x;//路径压缩
    }
    return x;
}

void Union(string x, string y, int t)//合并集合
{
    string a = findroot(x);//找到各自的根结点在map中的下标
    string b = findroot(y);
    string i;
    string j;
    string l;
    if(a != b)//不在一个集合内
    {
        i = (m[a].self >= m[b].self) ? a : b;//i为x、y的根结点中自身通信量较大者，j为较小者
        j = (m[a].self >= m[b].self) ? b : a;

        m[j].father = i;//将通信量较小者添加到通信量较大的
        m[i].sonnum += m[j].sonnum;//更新帮派人数
        m[i].sum = m[i].sum + m[j].sum + t;//更新总的通信量

        l = (m[x].self >= m[y].self) ? x : y;//l 为x、y中自身通信量较大的那个
        if(m[l].self > m[i].self)//帮派中自身通信量最大的那个人才能成为头目
        {
            m[i].father = l;
            m[l].father = l;
            m[l].sonnum = m[i].sonnum;
            m[l].sum = m[i].sum;
        }
    }
    else
    {
        m[a].sum += t;//帮派老大增加通信量

        l = (m[x].self >= m[y].self) ? x : y;//l 为x、y中自身通信量较大的那个
        if(m[l].self > m[i].self)//帮派中自身通信量最大的那个人才能成为头目
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
        m.clear();//初始化map

        string s1,s2;
        int t;

        for(int i=0; i<n; i++)//输入信息以及初始化
        {
            cin >> s1 >> s2 >> t;

            if(m.find(s1) == m.end())//map中没有存储过s1
            {
                person temp;
                temp.father = s1;
                temp.sonnum = 1;
                temp.self = t;
                temp.sum = 0;//总通信流量在合并的时候再追加到根结点
            }
            else
            {
                m[s1].self += t;
            }

            if(m.find(s2) == m.end())//map中没有存储过s2
            {
                person temp;
                temp.father = s2;
                temp.sonnum = 1;
                temp.self = t;
                temp.sum = 0;//总通信流量在合并的时候再追加到根结点
            }
            else
            {
                m[s2].self += t;
            }

            Union(s1,s2,t);
        }

        int num = 0;//黑帮数目
        vector<string> head;//存储黑帮头目的名字

        for(map<string,person>::iterator it = m.begin(); it != m.end(); it++)//定义迭代器遍历
        {
            if(it->second.father == it->first && it->second.sum > k && it->second.sonnum > 2)
            {
                head.push_back(it->first);//存储满足条件的黑帮头目
                num ++;
            }
        }

        sort(head.begin(),head.end());//头目名字按照字典序排序

        cout << num << endl;//输出
        for(int i=0; i<head.size(); i++)
        {
            cout << head[i] << " " << m[head[i]].sonnum << endl;
        }

    }
    return 0;
}
