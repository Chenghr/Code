#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>//����memset����

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
    bool operator< (const Point& p) const//���ȶ���Ĭ�ϴӴ�С���У�����С�����ȼ���
    {
        return dis > p.dis;
    }
};

int dis[MAXN];//���㵽Դ��ľ���
vector<Edge> graph[MAXN];//�洢ͼ

void Dijkstra(int s)//����±�
{
    priority_queue<Point> p;//δȷ���Ķ��㼯��
    dis[s] = 0;
    p.push(Point(s,dis[s]));//Դ�����

    while(!p.empty())//���зǿ�ʱ
    {
        int u = p.top().num;//δȷ���ĵ��о���Դ������ĵ�
        p.pop();

        for(int j=0; j<graph[u].size(); j++)
        {
            int v = graph[u][j].to;
            int d = graph[u][j].length;

            if(dis[u]+d < dis[v])//�ɳڲ���
            {
                dis[v] = dis[u]+d;
                p.push(Point(v,dis[v]));//���º�ĵ����
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
        memset(graph,0,sizeof(graph));//ͼ��ʼ��
        fill(dis,dis+n,INT_MAX);//�����ʼ��Ϊ����

        while(m--)
        {
            int from,to,length;
            cin >> from >> to >> length;
            graph[from].push_back(Edge(to,length));
            graph[to].push_back(Edge(from,length));
        }

        int s,t;
        cin >> s >> t;//����������յ�
        Dijkstra(s);

        if(dis[t] == INT_MAX) cout << -1 << endl;//���ɴ�
        else cout << dis[t] << endl;
    }
    return 0;
}
