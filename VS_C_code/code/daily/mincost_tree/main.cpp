#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 101;

struct Edge
{
    int from;
    int to;
    int length;
    bool operator<(const Edge& e) const//重载小于号，便于sort算法的使用
    {
        return length < e.length;
    }
};

int father[MAXN];//保存父亲结点的下标
int height[MAXN];//结点高度
Edge edge[MAXN*MAXN];//边集

void initial(int n)//初始化函数
{
    for(int i=0; i<n; i++)
    {
        father[i] = i;//标志结点为独立的结点
        height[i] = 1;
    }
}

int Find(int x)//查找x的根结点
{
    if(father[x] != x)
    {
        father[x] = Find(father[x]);//路径压缩，减少下次查找次数
    }
    return x;
}

void Union(int x, int y)//合并结点
{
    x = father[x];
    y = father[y];

    if(x != y)//x，y不属于同一连通分量时
    {
        if(height[x] > height[y])//结点高度低的结点合并到结点高度高的结点
        {
            father[y] = x;
        }
        else if(height[x] < height[y])
        {
            father[x] = y;
        }
        else//结点高度相同，根结点高度增1
        {
            father[y] = x;
            height[x] += 1;
        }
    }
}

int MinCostTree(int m)
{
    sort(edge,edge+m);//边按照权值从小到大排序

    int mincost = 0;
    for(int i=0; i<m; i++)//依次遍历边
    {
        Edge current = edge[i];
        if(Find(current.from) != Find(current.to))
        {
            Union(current.from,current.to);//选取边，合并端点
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
