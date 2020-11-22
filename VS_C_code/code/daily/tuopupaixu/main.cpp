#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>//包含memset函数

using namespace std;

const int MAXN = 101;

int indegree[MAXN];//存储各顶点的入度
vector<int> graph[MAXN];//存储图,只用存储边对应的两个端点，不用存储边长

vector<int> ToPologicalSort(int n)//用向量存储结果并返回
{
    vector<int> topology;//存储拓扑序列
    priority_queue<int, vector<int>, greater<int> > node;//采用优先队列，入度为0的结点优先输出编号较小的

    for(int i=0; i<n; i++)//初始化，找出入度为0的顶点入队
    {
        if(indegree[i] == 0) node.push(i);
    }

    while(!node.empty())
    {
        int u = node.top();
        node.pop();
        topology.push_back(u);

        for(int i=0; i<graph[u].size(); i++)//遍历u为出发点的边，依次删除，即终点的入度-1
        {
            int v = graph[u][i];
            indegree[v] --;
            if(indegree[v] == 0)//如果终点的入度为0，则入队
            {
                node.push(v);
            }
        }
    }
    return topology;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        memset(graph,0,sizeof(graph));//图初始化
        fill(indegree,indegree+n,0);//入度初始化为0

        while(m--)
        {
            int from,to;
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to] ++;
        }

        vector<int> ans = ToPologicalSort(n);

        if(ans.size() == n)//拓扑序列存在
        {
            for(int i=0; i<n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else//拓扑序列不存在
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
