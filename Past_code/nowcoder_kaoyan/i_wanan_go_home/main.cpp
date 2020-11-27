#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>//memset函数
#include <climits>
#include <queue>

using namespace std;

const int MAXN = 601;
const int INF = 0x3f3f3f3f;

struct Edge{
    int to;
    int length;
    Edge(int t, int l): to(t), length(l) {}
};

struct Point{
    int number;
    int distance;
    Point(int n, int d): number(n), distance(d) {}
    bool operator< (const Point& p) const
    {
        return distance > p.distance;
    }
};

vector<Edge> g[MAXN];
int dis[MAXN];
int arr[MAXN];

void Dijkstra(int s) //优先队列优化的Dijkstra算法
{
    priority_queue<Point> PQ;
    dis[s] = 0;
    PQ.push(Point(s, dis[s]));
    while(!PQ.empty())
    {
        int u = PQ.top().number;
        PQ.pop();
        for(int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i].to;
            int l = g[u][i].length;
            if(!(arr[u-1] == 2 && arr[v-1] == 1) && (dis[v] > dis[u] + l))//出现从阵营2到阵营1的情况则不符合条件
            {
                dis[v] = dis[u] + l;
                PQ.push(Point(v, dis[v]));
            }
        }
    }
}


int main(){
    int n, m;
    while(cin >> n && n)
    {
        cin >> m;

        memset(g, 0, sizeof(g));
        memset(dis, 0x3f, sizeof(dis));

        for(int i = 0; i < m; ++i)
        {
            int from, to, length;
            cin >> from >> to >> length;
            g[from].push_back(Edge(to, length));
            g[to].push_back(Edge(from, length));
        }

        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        Dijkstra(1);

        if(dis[2] == INF)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << dis[2] << endl;
        }
    }
    return 0;
}

