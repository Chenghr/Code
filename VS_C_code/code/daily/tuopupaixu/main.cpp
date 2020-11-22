#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>//����memset����

using namespace std;

const int MAXN = 101;

int indegree[MAXN];//�洢����������
vector<int> graph[MAXN];//�洢ͼ,ֻ�ô洢�߶�Ӧ�������˵㣬���ô洢�߳�

vector<int> ToPologicalSort(int n)//�������洢���������
{
    vector<int> topology;//�洢��������
    priority_queue<int, vector<int>, greater<int> > node;//�������ȶ��У����Ϊ0�Ľ�����������Ž�С��

    for(int i=0; i<n; i++)//��ʼ�����ҳ����Ϊ0�Ķ������
    {
        if(indegree[i] == 0) node.push(i);
    }

    while(!node.empty())
    {
        int u = node.top();
        node.pop();
        topology.push_back(u);

        for(int i=0; i<graph[u].size(); i++)//����uΪ������ıߣ�����ɾ�������յ�����-1
        {
            int v = graph[u][i];
            indegree[v] --;
            if(indegree[v] == 0)//����յ�����Ϊ0�������
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
        memset(graph,0,sizeof(graph));//ͼ��ʼ��
        fill(indegree,indegree+n,0);//��ȳ�ʼ��Ϊ0

        while(m--)
        {
            int from,to;
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to] ++;
        }

        vector<int> ans = ToPologicalSort(n);

        if(ans.size() == n)//�������д���
        {
            for(int i=0; i<n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else//�������в�����
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
