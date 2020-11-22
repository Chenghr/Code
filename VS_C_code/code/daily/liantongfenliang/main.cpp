#include <iostream>

using namespace std;

const int MAXN = 101;

int father[MAXN];//保存父亲结点的下标
int height[MAXN];//结点高度

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

int main()
{
    int n,m;//结点数以及边的数目
    while(cin >> n >> m)
    {
        initial(n);

        for(int i=0; i<m; i++)
        {
            int from,to;
            cin >> from >> to;
            Union(from,to);
        }

        int num = 0;
        for(int i=0; i<n; i++)
        {
            if(father[i] == i)
            {
                num ++;
            }
        }

        cout << num << endl;
    }
    return 0;
}
