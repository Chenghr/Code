#include <iostream>

using namespace std;

const int maxn = 1000000;
int father[maxn];
int height[maxn];
int tag[maxn];

void initial()//初始化
{
    for (int i=0; i<maxn; i++)
    {
        father[i] = i;
        height[i] = 0;
        tag[i] =0;
    }
}

int findroot(int x)//查找根节点
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);//路径压缩
    }
    return father[x];
}

void Union(int x, int y)//合并集合
{
    x = findroot(x);//找到各自的根结点
    y = findroot(y);

    if(x != y)//不在一个集合内
    {
        if(height[x] < height[y])//矮树作为高树的子树
        {
            father[x] = y;
        }
        else if(height[y] < height[x])
        {
            father[y] = x;
        }
        else//两棵树高度相同，由于路径压缩后一个树的最大高度为2，所以被添加的树高度加一即可
        {
            father[y] = x;
            height[x] ++;
        }
    }

    return ;
}

int main()
{
    initial();//初始化

    int a,b,m = 0;
    while (cin >> a >> b)
    {
        if(a > m) m = a;
        if(b > m) m = b;

        tag[a] = 1;
        tag[b] = 1;
        Union(a,b);
    }

    int conpoent = 0;
    for(int i=0; i<=m; i++)
    {
        if(tag[i] == 1 && father[i] == i)
        {
            conpoent ++;
        }
    }
    cout << conpoent << endl;

    return 0;
}
