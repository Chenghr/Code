#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 601;
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
int dis1[MAXN];//1到本阵营的所有结点最短距离
int dis2[MAXN];//2到本阵营的所有结点最短距离
int tag[MAXN];//阵营标记

void dijkstra(int s,int tag)//输入起点下标,所属阵营
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
        fill(dis,dis+n,INF);//初始化距离函数
        memset(graph,0,sizeof(graph));//图初始化

        for(int i=0; i<m; i++)
        {
            int from,to,length;
            cin >> from >> to >> length;

            vector<Edge> :: iterator it;
            if(graph[from].find())
            {
                graph[from].push_back(Edge(to,length));//向图内存储路径
                graph[to].push_back(Edge(from,length));
            }
            length = length*2%100000;
        }



    }
    return 0;
}

/*
const int N = 601;
int graph[N][N];//城市间距离
int camp[N];//各个城市的阵营
int n[3];//n[0]:城市数量；n[1]、n[2]分别表示两个阵营各自的城市数量
int d1[N],d2[N];//分别存储1、2到各自阵营的城市的最短路径
bool mark[N];//标记点是否在集合里

void dijkstra(int s,int t)//源点s,阵营1
{

}

int main()
{
    while(cin >> n[0])
    {
        if(n == 0) break;

        fill(graph,N*N,INT_MAX);//初始化邻接矩阵
        for(int i=0; i<n; i++)
        {
            graph[i][i] = 0;
        }

        int m;
        cin >> m;
        for(int i=0; i<m; i++)//输入边
        {
            int from,to,length;
            cin >> from >> to >> length;
            if(graph[from][to] > length)
            {
                graph[from][to] = length;
                graph[to][from] = length;
            }
        }

        n[1] = 0;
        n[2] = 0;
        for(int i=0; i<n; i++)//输入阵营标记
        {
            cin >> camp[i];
            if(camp[i] == 1) n[1] ++;
            else n[2] ++;
        }


    }
    return 0;
}
*/
