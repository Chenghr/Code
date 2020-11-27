#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Edge
{
    int from;
    int to;
    double length;
};

const int N = 101;
Point point[N];
Edge edge[N*N];
int father[N];
int height[N];

bool comp(Edge x, Edge y)
{
    return x.length < y.length;
}

double caculate(double x,double y)
{
    double a = pow(x,2);
    double b = pow(y,2);
    return sqrt(a+b);
}

int findroot(int x)//Ѱ�Ҹ����
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);//·��ѹ��
    }
    return father[x];
}

void Union(int x,int y)//ֻ�в���ͬһ����ʱ�Ż�ϲ�
{
    int a = findroot(x);
    int b = findroot(y);
    if(a != b)
    {
        if(height[a] > height[b])//�߶ȵ͵ĺϲ����߶ȸߵ�
        {
            father[b] = a;
        }
        else if(height[a] < height[b])
        {
            father[a] = b;
        }
        else//�߶���ͬʱ���ϲ������ĸ߶�Ҫ���ӵ�
        {
            father[b] = a;
            height[a] ++;
        }
    }
    return ;
}

double kruskal(int n)
{
    int edgenum = n*(n-1)/2;
    sort(edge,edge+edgenum,comp);//���߰��ճ�������

    double sumlength = 0;
    for(int i=0; i<edgenum; i++)//���α�����
    {
        Edge current = edge[i];
        if(findroot(current.from) != findroot(current.to))//�ߵ����˶��㲻��ͬһ����ʱ
        {
            sumlength += current.length;//ѡȡ��
            Union(current.from, current.to);
        }
    }
    return sumlength;
}

int main()
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        for(int i=0; i<n; i++)//��ʼ��
        {
            scanf("%lf%lf",&point[i].x,&point[i].y);
            father[i] = i;
            height[i] = 0;
        }

        int k = 0;
        for(int i=0; i<n; i++)//��ʼ����
        {
            for(int j=i+1; j<n; j++)
            {
                edge[k].from = i;
                edge[k].to = j;
                edge[k].length = caculate(point[i].x-point[j].x, point[i].y-point[j].y);
                k ++;
            }
        }

        double length = kruskal(n);

        printf("%.2lf\n",length);
    }
    return 0;
}
