#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
};

const int N = 27;
Edge e[N];
int father[N];
int height[N];

void initial(int n)//��ʼ������
{
    for(int i=0; i<n; i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

bool comp(Edge x, Edge y)
{
    return x.cost < y.cost;
}

int findroot(int x)//���Ҹ��ڵ�
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);//·��ѹ��
    }
    return father[x];
}

void Union(int x, int y)//�ϲ�����ͬһ�����ڵ������ڵ�
{
    int a = findroot(x);
    int b = findroot(y);

    if(a != b)//����ͬһ������
    {
        if(height[a] > height[b])//���͵ļ������ߵ�
        {
            father[b] = a;
        }
        else if(height[a] < height[b])
        {
            father[a] = b;
        }
        else//�߶���ͬʱ�������Ҫ���Ӹ߶�
        {
            father[b] = a;
            height[a] ++;
        }
    }
    return ;
}

int kruskal(int n, int edgenum)//��С�������㷨
{
    sort(e, e+edgenum, comp);//�߰��ջ�������

    int sum = 0;
    for(int i=0; i<edgenum; i++)
    {
        Edge current = e[i];
        if(findroot(current.from) != findroot(current.to))
        {
            sum += current.cost;
            Union(current.from,current.to);
        }
    }
    return sum;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;

        initial(n);//��ʼ��
        int edgenum = 0;
        for(int i=0; i<n-1; i++)//����n-1������
        {
            string s1;
            int k;
            cin >> s1 >> k;

            for(int j=0; j<k; j++)//k����·
            {
                string s2;
                int price;
                cin >> s2 >> price;
                e[edgenum].from = s1[0]-'A';
                e[edgenum].to = s2[0]-'A';
                e[edgenum].cost = price;
                edgenum ++;
            }
        }

        int cost = kruskal(n,edgenum);
        cout << cost << endl;
    }
    return 0;
}
