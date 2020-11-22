#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>//包含memset函数

using namespace std;

const int MAXN = 101;

struct Edge
{
    int to;
    int length;
};

vector<int> graph[MAXN];//存储图,只用存储边对应的两个端点，不用存储边长
int indegree[MAXN];//存储各顶点的入度
int earliest[MAXN];//最早开始时间
int latest[MAXN];//最晚开始时间
int time[MAXN];//花费时间

int CriticalPath(int n)//用向量存储结果并返回
{
    vector<int> topology;//存储拓扑序列
    queue<int> node;

    for(int i=1; i<=n; i++)//初始化，找出入度为0的顶点入队，从1开始存储
    {
        if(indegree[i] == 0)
            node.push(i);
    }

    int totalTime = 0;//关键路径的长度

    //在构造出拓扑序列的同时得出最早开始时间
    while(!node.empty())
    {
        int u = node.front();
        node.pop();
        topology.push_back(u);

        for(int i=0; i<graph[u].size(); i++)//遍历u为出发点的边，依次删除，即终点的入度-1
        {
            int v = graph[u][i];
            indegree[v] --;

            earliest[v] = max(earliest[v],earliest[u]+time[u]);//最早开始时间为全部先序活动的最晚开始时间，u为v的前驱节点

            if(indegree[v] == 0)//如果终点的入度为0，则入队
            {
                node.push(v);

                totalTime = max(totalTime,earliest[v]+time[v]);//最早开始时间的最大值为关键路径的总长度
            }
        }
    }

    //逆序遍历拓扑序列，得出最晚开始时间，这个是用于求出关键活动的，若仅求出关键路径长度，仅求出最早开始时间即可
    for(int i=topology.size()-1; i>=0; i--)
    {
        int u = topology[i];

        if(graph[u].size() == 0)//初始化latest[u]，汇点初始化为它的最早开始时间
        {
            latest[u] = totalTime - time[u];//汇点的time[u]=0
        }
        else//非汇点初始化为无穷大
        {
            latest[u] = INT_MAX;
        }

        for(int j=0; j<graph[u].size(); j++)
        {
            int v = graph[u][j];
            latest[u] = min(latest[u],latest[v]-time[u]);//自己画个AOE网模拟下求解过程就能理解这个式子
        }
    }
    return totalTime;
}

int main()
{
    int n,m;//n个活动，m个关系
    while(cin >> n >> m)
    {
        memset(graph,0,sizeof(graph));//图初始化
        memset(indegree,0,sizeof(indegree));
        memset(earliest,0,sizeof(earliest));
        memset(latest,0,sizeof(latest));
        memset(time,0,sizeof(time));

        for(int i=1; i<=n; i++)//从1开始存储
        {
            cin >> time[i];//完成每个活动需要的时间
        }

        while(m--)
        {
            int from,to;
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to] ++;
        }

        int totaltime = CriticalPath(n);

        cout << totaltime << endl;
        for(int i=0; i<n; i++)
        {
            cout << earliest[i] << " ";
        }
        cout << endl;
        for(int i=0; i<n; i++)
        {
            cout << latest[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
