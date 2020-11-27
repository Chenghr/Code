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

bool IsTarget(string s)//判断某个字符串是否含有2012
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
    map <string,int> maptest;//用于判断串是否出现过
    q.push(s);//原始串入队
    maptest[s.code] = 1;

    while (!q.empty())
    {
        STR temp = q.front();
        q.pop();

        if(IsTarget(temp.code))
            return temp.deep;//找到目标状态

        for(int i=0; i<temp.code.size()-1; i++)//依次交换出下个状态
        {
            string a = temp.code;//交换
            char ch = a[i];
            a[i] = a[i+1];
            a[i+1] = ch;

            if(maptest.find(a) == maptest.end())//交换后的新串没有出现过
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
