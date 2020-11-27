#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

const int MAXN = 100001;

int indegree[MAXN];//入度
vector<int> graph[MAXN];

vector<int> TopologicalSort(int n)
{
    vector<int> topology;//拓扑序列
    priority_queue<int, vector<int>, greater<int> > node;//小顶堆,存储入度为0的结点

    for(int i=0; i<n; i++)
    {
        if(indegree[i] == 0) node.push(i);
    }

    while(!node.empty())//不为空
    {
        int u = node.top();
        node.pop();
        topology.push_back(u);//结点数较小的先出队存储

        for(int i=0; i<graph[u].size(); i++)//遍历以u为出发点的边
        {
            int v = graph[u][i];//边的终点为v
            indegree[v] --;//删除边，v的入度-1
            if(indegree[v] == 0)//如果v的入度为0了，则存入小顶堆
            {
                node.push(v);
            }
        }
    }

    return topology;
}

int main()
{
    int n;
    while(cin >> n)
    {
        string s;
        cin.get();//吃回车

        for(int i=0; i<n; i++)
        {
            getline(cin,s);
            vector<int> temp;

            for(int i=0; i<s.size(); i++)
            {
                if(isdigit(s[i]))
                {
                    temp.push_back(s[i]-'0');
                }
            }

            if(temp.size() > 1)
            {
                int u = temp[0]-'0';
                for(int i=1; i<temp.size(); i++)
                {
                    graph[u].push_back(temp[i]-'0');
                }
            }
        }

        vector<int> answer = TopologicalSort(n);

        for(int i=0; i<answer.size(); i++)
        {
            cout << "Task" << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
