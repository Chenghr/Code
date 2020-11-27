#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

const int MAXN = 100001;

int indegree[MAXN];//���
vector<int> graph[MAXN];

vector<int> TopologicalSort(int n)
{
    vector<int> topology;//��������
    priority_queue<int, vector<int>, greater<int> > node;//С����,�洢���Ϊ0�Ľ��

    for(int i=0; i<n; i++)
    {
        if(indegree[i] == 0) node.push(i);
    }

    while(!node.empty())//��Ϊ��
    {
        int u = node.top();
        node.pop();
        topology.push_back(u);//�������С���ȳ��Ӵ洢

        for(int i=0; i<graph[u].size(); i++)//������uΪ������ı�
        {
            int v = graph[u][i];//�ߵ��յ�Ϊv
            indegree[v] --;//ɾ���ߣ�v�����-1
            if(indegree[v] == 0)//���v�����Ϊ0�ˣ������С����
            {
                node.push(v);
            }
        }
    }

    return topology;
}

int main()
{
    int n;
    while(cin >> n)
    {
        string s;
        cin.get();//�Իس�

        for(int i=0; i<n; i++)
        {
            getline(cin,s);
            vector<int> temp;

            for(int i=0; i<s.size(); i++)
            {
                if(isdigit(s[i]))
                {
                    temp.push_back(s[i]-'0');
                }
            }

            if(temp.size() > 1)
            {
                int u = temp[0]-'0';
                for(int i=1; i<temp.size(); i++)
                {
                    graph[u].push_back(temp[i]-'0');
                }
            }
        }

        vector<int> answer = TopologicalSort(n);

        for(int i=0; i<answer.size(); i++)
        {
            cout << "Task" << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
