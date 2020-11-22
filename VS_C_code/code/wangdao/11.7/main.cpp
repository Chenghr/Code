#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 601;
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
int dis1[MAXN];//1������Ӫ�����н����̾���
int dis2[MAXN];//2������Ӫ�����н����̾���
int tag[MAXN];//��Ӫ���

void dijkstra(int s,int tag)//��������±�,������Ӫ
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
        fill(dis,dis+n,INF);//��ʼ�����뺯��
        memset(graph,0,sizeof(graph));//ͼ��ʼ��

        for(int i=0; i<m; i++)
        {
            int from,to,length;
            cin >> from >> to >> length;

            vector<Edge> :: iterator it;
            if(graph[from].find())
            {
                graph[from].push_back(Edge(to,length));//��ͼ�ڴ洢·��
                graph[to].push_back(Edge(from,length));
            }
            length = length*2%100000;
        }



    }
    return 0;
}

/*
const int N = 601;
int graph[N][N];//���м����
int camp[N];//�������е���Ӫ
int n[3];//n[0]:����������n[1]��n[2]�ֱ��ʾ������Ӫ���Եĳ�������
int d1[N],d2[N];//�ֱ�洢1��2��������Ӫ�ĳ��е����·��
bool mark[N];//��ǵ��Ƿ��ڼ�����

void dijkstra(int s,int t)//Դ��s,��Ӫ1
{

}

int main()
{
    while(cin >> n[0])
    {
        if(n == 0) break;

        fill(graph,N*N,INT_MAX);//��ʼ���ڽӾ���
        for(int i=0; i<n; i++)
        {
            graph[i][i] = 0;
        }

        int m;
        cin >> m;
        for(int i=0; i<m; i++)//�����
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
        for(int i=0; i<n; i++)//������Ӫ���
        {
            cin >> camp[i];
            if(camp[i] == 1) n[1] ++;
            else n[2] ++;
        }


    }
    return 0;
}
*/
