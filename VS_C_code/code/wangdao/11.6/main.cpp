//天坑，这题有重复输入，检测到第二次输入时，不应该向图中添加路径
//用并查集的板子来解决重复输入的问题，两个结点已经是联通的，就不要再继续覆盖路径了

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>//包含fill函数
#include <cstring>//包含memset函数
#include <climits>//包含INT_MAX

using namespace std;

const int MAXN = 101;
const int INF = INT_MAX;

struct Edge//源点即为下标
{
    int to;//终点下标
    int length;//路径长度
    Edge(int t, int l) : to(t),length(l) {}
};

struct Point
{
    int num;//点的编号
    int dist;//源点到该点的距离
    Point(int n, int d) : num(n),dist(d) {}
    bool operator< (const Point& p) const
    {
        return dist > p.dist;//优先队列输出的是最大的那个，距离越近的优先级应该越高
    }
};

vector<Edge> graph[MAXN];//存储图，graph[i]存储以i为出发结点的所有边
int dis[MAXN];//存储所有结点到目标结点的距离
int father[MAXN];
int height[MAXN];

void initial(int n)
{
    for(int i=0; i<n; i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

int findroot(int x)
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    int a = findroot(x);
    int b = findroot(y);
    if(a != b)
    {
        if(height[a] > height[b])
        {
            father[b] = a;
        }
        else if(height[a] < height[b])
        {
            father[a] = b;
        }
        else
        {
            father[b] = a;
            height[a] ++;
        }
    }
    return ;
}

void dijkstra(int s)//输入起点下标
{
    priority_queue<Point> q;//优先级队列
    dis[s] = 0;
    q.push(Point(s,dis[s]));//入队

    while(!q.empty())//队列不空时
    {
        int u = q.top().num;//距离源点最近的点的编号
        q.pop();//队首元素出队

        for(int i=0; i<graph[u].size(); i++)//遍历以u为头结点的所有边
        {
            int v = graph[u][i].to;//当前边的终点
            int d = graph[u][i].length;//u到v的距离
            if(dis[v] > dis[u]+d)//松弛操作，发现距离更近的一条路时，更新路径
            {
                dis[v] = dis[u]+d;
                q.push(Point(v,dis[v]));//将更新后的结点入队
            }
        }
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        initial(n);
        fill(dis,dis+n,INF);//初始化距离函数
        memset(graph,0,sizeof(graph));//图初始化

        int length = 1;
        for(int i=0; i<m; i++)
        {
            int from,to;
            cin >> from >> to;

            if(findroot(from) != findroot(to))
            {
                graph[from].push_back(Edge(to,length));//向图内存储路径
                graph[to].push_back(Edge(from,length));
                Union(from,to);
            }
            length = length*2%100000;
        }

        dijkstra(0);

        for(int i=1; i<n; i++)
        {
            if(dis[i] == INF) cout << "-1" << endl;
            else cout << dis[i]%100000 << endl;
        }

    }
    return 0;
}
