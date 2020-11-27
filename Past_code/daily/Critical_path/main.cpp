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
};

vector<int> graph[MAXN];//�洢ͼ,ֻ�ô洢�߶�Ӧ�������˵㣬���ô洢�߳�
int indegree[MAXN];//�洢����������
int earliest[MAXN];//���翪ʼʱ��
int latest[MAXN];//����ʼʱ��
int time[MAXN];//����ʱ��

int CriticalPath(int n)//�������洢���������
{
    vector<int> topology;//�洢��������
    queue<int> node;

    for(int i=1; i<=n; i++)//��ʼ�����ҳ����Ϊ0�Ķ�����ӣ���1��ʼ�洢
    {
        if(indegree[i] == 0)
            node.push(i);
    }

    int totalTime = 0;//�ؼ�·���ĳ���

    //�ڹ�����������е�ͬʱ�ó����翪ʼʱ��
    while(!node.empty())
    {
        int u = node.front();
        node.pop();
        topology.push_back(u);

        for(int i=0; i<graph[u].size(); i++)//����uΪ������ıߣ�����ɾ�������յ�����-1
        {
            int v = graph[u][i];
            indegree[v] --;

            earliest[v] = max(earliest[v],earliest[u]+time[u]);//���翪ʼʱ��Ϊȫ������������ʼʱ�䣬uΪv��ǰ���ڵ�

            if(indegree[v] == 0)//����յ�����Ϊ0�������
            {
                node.push(v);

                totalTime = max(totalTime,earliest[v]+time[v]);//���翪ʼʱ������ֵΪ�ؼ�·�����ܳ���
            }
        }
    }

    //��������������У��ó�����ʼʱ�䣬�������������ؼ���ģ���������ؼ�·�����ȣ���������翪ʼʱ�伴��
    for(int i=topology.size()-1; i>=0; i--)
    {
        int u = topology[i];

        if(graph[u].size() == 0)//��ʼ��latest[u]������ʼ��Ϊ�������翪ʼʱ��
        {
            latest[u] = totalTime - time[u];//����time[u]=0
        }
        else//�ǻ���ʼ��Ϊ�����
        {
            latest[u] = INT_MAX;
        }

        for(int j=0; j<graph[u].size(); j++)
        {
            int v = graph[u][j];
            latest[u] = min(latest[u],latest[v]-time[u]);//�Լ�����AOE��ģ���������̾���������ʽ��
        }
    }
    return totalTime;
}

int main()
{
    int n,m;//n�����m����ϵ
    while(cin >> n >> m)
    {
        memset(graph,0,sizeof(graph));//ͼ��ʼ��
        memset(indegree,0,sizeof(indegree));
        memset(earliest,0,sizeof(earliest));
        memset(latest,0,sizeof(latest));
        memset(time,0,sizeof(time));

        for(int i=1; i<=n; i++)//��1��ʼ�洢
        {
            cin >> time[i];//���ÿ�����Ҫ��ʱ��
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
