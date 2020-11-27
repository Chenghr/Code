//��ӣ��������ظ����룬��⵽�ڶ�������ʱ����Ӧ����ͼ�����·��
//�ò��鼯�İ���������ظ���������⣬��������Ѿ�����ͨ�ģ��Ͳ�Ҫ�ټ�������·����

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>//����fill����
#include <cstring>//����memset����
#include <climits>//����INT_MAX

using namespace std;

const int MAXN = 101;
const int INF = INT_MAX;

struct Edge//Դ�㼴Ϊ�±�
{
    int to;//�յ��±�
    int length;//·������
    Edge(int t, int l) : to(t),length(l) {}
};

struct Point
{
    int num;//��ı��
    int dist;//Դ�㵽�õ�ľ���
    Point(int n, int d) : num(n),dist(d) {}
    bool operator< (const Point& p) const
    {
        return dist > p.dist;//���ȶ���������������Ǹ�������Խ�������ȼ�Ӧ��Խ��
    }
};

vector<Edge> graph[MAXN];//�洢ͼ��graph[i]�洢��iΪ�����������б�
int dis[MAXN];//�洢���н�㵽Ŀ����ľ���
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

void dijkstra(int s)//��������±�
{
    priority_queue<Point> q;//���ȼ�����
    dis[s] = 0;
    q.push(Point(s,dis[s]));//���

    while(!q.empty())//���в���ʱ
    {
        int u = q.top().num;//����Դ������ĵ�ı��
        q.pop();//����Ԫ�س���

        for(int i=0; i<graph[u].size(); i++)//������uΪͷ�������б�
        {
            int v = graph[u][i].to;//��ǰ�ߵ��յ�
            int d = graph[u][i].length;//u��v�ľ���
            if(dis[v] > dis[u]+d)//�ɳڲ��������־��������һ��·ʱ������·��
            {
                dis[v] = dis[u]+d;
                q.push(Point(v,dis[v]));//�����º�Ľ�����
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
        fill(dis,dis+n,INF);//��ʼ�����뺯��
        memset(graph,0,sizeof(graph));//ͼ��ʼ��

        int length = 1;
        for(int i=0; i<m; i++)
        {
            int from,to;
            cin >> from >> to;

            if(findroot(from) != findroot(to))
            {
                graph[from].push_back(Edge(to,length));//��ͼ�ڴ洢·��
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
