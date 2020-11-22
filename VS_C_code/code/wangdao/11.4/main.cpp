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

int findroot(int x)//寻找根结点
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);//路径压缩
    }
    return father[x];
}

void Union(int x,int y)//只有不在同一集合时才会合并
{
    int a = findroot(x);
    int b = findroot(y);
    if(a != b)
    {
        if(height[a] > height[b])//高度低的合并到高度高的
        {
            father[b] = a;
        }
        else if(height[a] < height[b])
        {
            father[a] = b;
        }
        else//高度相同时，合并后树的高度要增加的
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
    sort(edge,edge+edgenum,comp);//将边按照长度排序

    double sumlength = 0;
    for(int i=0; i<edgenum; i++)//依次遍历边
    {
        Edge current = edge[i];
        if(findroot(current.from) != findroot(current.to))//边的两端顶点不在同一集合时
        {
            sumlength += current.length;//选取边
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
        for(int i=0; i<n; i++)//初始化
        {
            scanf("%lf%lf",&point[i].x,&point[i].y);
            father[i] = i;
            height[i] = 0;
        }

        int k = 0;
        for(int i=0; i<n; i++)//初始化边
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
