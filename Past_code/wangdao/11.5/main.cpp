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

void initial(int n)//初始化函数
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

int findroot(int x)//查找根节点
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);//路径压缩
    }
    return father[x];
}

void Union(int x, int y)//合并不在同一集合内的两个节点
{
    int a = findroot(x);
    int b = findroot(y);

    if(a != b)//不在同一集合内
    {
        if(height[a] > height[b])//树低的加入树高的
        {
            father[b] = a;
        }
        else if(height[a] < height[b])
        {
            father[a] = b;
        }
        else//高度相同时，插入后要增加高度
        {
            father[b] = a;
            height[a] ++;
        }
    }
    return ;
}

int kruskal(int n, int edgenum)//最小生成树算法
{
    sort(e, e+edgenum, comp);//边按照花费排序

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

        initial(n);//初始化
        int edgenum = 0;
        for(int i=0; i<n-1; i++)//输入n-1行数据
        {
            string s1;
            int k;
            cin >> s1 >> k;

            for(int j=0; j<k; j++)//k条线路
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
