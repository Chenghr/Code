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
    Edge(int t, int l) : to(t),length(l) {}
};

struct Point
{
    int num;
    int dis;
    Point(int n,int d) : num(n),dis(d) {}
    bool operator< (const Point& p) const//优先队列默认从大到小排列，距离小的优先级高
    {
        return dis > p.dis;
    }
};

int dis[MAXN];//各点到源点的距离
vector<Edge> graph[MAXN];//存储图

void Dijkstra(int s)//起点下标
{
    priority_queue<Point> p;//未确定的顶点集合
    dis[s] = 0;
    p.push(Point(s,dis[s]));//源点入队

    while(!p.empty())//队列非空时
    {
        int u = p.top().num;//未确定的点中距离源点最近的点
        p.pop();

        for(int j=0; j<graph[u].size(); j++)
        {
            int v = graph[u][j].to;
            int d = graph[u][j].length;

            if(dis[u]+d < dis[v])//松弛操作
            {
                dis[v] = dis[u]+d;
                p.push(Point(v,dis[v]));//更新后的点入队
            }
        }
    }

    return ;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        memset(graph,0,sizeof(graph));//图初始化
        fill(dis,dis+n,INT_MAX);//距离初始化为无穷

        while(m--)
        {
            int from,to,length;
            cin >> from >> to >> length;
            graph[from].push_back(Edge(to,length));
            graph[to].push_back(Edge(from,length));
        }

        int s,t;
        cin >> s >> t;//出入起点与终点
        Dijkstra(s);

        if(dis[t] == INT_MAX) cout << -1 << endl;//不可达
        else cout << dis[t] << endl;
    }
    return 0;
}
