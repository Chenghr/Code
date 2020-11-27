#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 101;

struct Edge
{
    int from;
    int to;
    int length;
    bool operator<(const Edge& e) const//����С�ںţ�����sort�㷨��ʹ��
    {
        return length < e.length;
    }
};

int father[MAXN];//���游�׽����±�
int height[MAXN];//���߶�
Edge edge[MAXN*MAXN];//�߼�

void initial(int n)//��ʼ������
{
    for(int i=0; i<n; i++)
    {
        father[i] = i;//��־���Ϊ�����Ľ��
        height[i] = 1;
    }
}

int Find(int x)//����x�ĸ����
{
    if(father[x] != x)
    {
        father[x] = Find(father[x]);//·��ѹ���������´β��Ҵ���
    }
    return x;
}

void Union(int x, int y)//�ϲ����
{
    x = father[x];
    y = father[y];

    if(x != y)//x��y������ͬһ��ͨ����ʱ
    {
        if(height[x] > height[y])//���߶ȵ͵Ľ��ϲ������߶ȸߵĽ��
        {
            father[y] = x;
        }
        else if(height[x] < height[y])
        {
            father[x] = y;
        }
        else//���߶���ͬ�������߶���1
        {
            father[y] = x;
            height[x] += 1;
        }
    }
}

int MinCostTree(int m)
{
    sort(edge,edge+m);//�߰���Ȩֵ��С��������

    int mincost = 0;
    for(int i=0; i<m; i++)//���α�����
    {
        Edge current = edge[i];
        if(Find(current.from) != Find(current.to))
        {
            Union(current.from,current.to);//ѡȡ�ߣ��ϲ��˵�
            mincost += current.length;
        }
    }

    return mincost;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        initial(n);
        for(int i=0; i<m; i++)
        {
            cin >> edge[i].from >> edge[i].to >> edge[i].length;
        }

        int mincost = MinCostTree(m);
        cout << mincost << endl;
    }
    return 0;
}
