#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 400;

int father[MAXN];
int height[MAXN];
vector<int> edge[MAXN];

void initial(int n)
{
    for(int i=0; i<=n; i++)//结点下标从1开始
    {
        father[i] = i;
        height[i] = 1;
    }
}

int Find(int x)//查找根节点
{
    if(father[x] != x)
    {
        father[x] = Find(father[x]);//路径压缩
    }
    return x;
}

void Union(int x, int y)//合并结点
{
    x = father[x];
    y = father[y];
    if(x != y)
    {
        if(height[x] > height[y])
        {
            father[y] = x;
        }
        else if(height[x] < height[y])
        {
            father[x] = y;
        }
        else
        {
            father[y] = x;
            height[x] ++;
        }
    }

}

bool IsTarget(int n,int x)
{
    initial(n);//初始化
    for(int i=1; i<=n; i++)//连通图
    {
        if(i != x)//边的出发点删除x
        {
            for(int j=0; j<edge[i].size(); j++)
            {
                if(edge[i][j] != x)//边的到达点删除x
                {
                    Union(i,edge[i][j]);
                }
            }
        }
    }

    int num = 0;//连通分量数目
    for(int i=1; i<=n; i++)
    {
        if(i != x && i == father[i])
        {
            num ++;
        }
    }
    if(num > 1) return true;
    return false;
}

int main()
{
    ifstream fin("input4.txt");

    int n;//顶点数目
    fin >> n;

    int from,to;//读取边
    while (!fin.eof())
    {
        fin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    int tag = 0;//标记是否有解
    for(int i=1; i<=n; i++)
    {
        if(IsTarget(n,i))
        {
            tag = 1;
            cout << i << endl;
            break;
        }
    }
    if(tag == 0)
        cout << "不存在满足要求的顶点！" << endl;

    return 0;
}
