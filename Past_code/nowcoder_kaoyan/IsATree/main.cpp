#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10001;

int father[MAXN];//父节点
int height[MAXN];
int indegree[MAXN];//当前结点入度
int tag[MAXN];//标记结点是否出现过
int n_max;//标记出现的结点最大序号
int input_num = 1;

vector<int> edge[MAXN];//存储边

void initial()
{
    for(int i=0; i<=MAXN; i++)
    {
        father[i] = i;
        height[i] = 1;
        indegree[i] = 0;
        tag[i] = 0;
    }
}

int Find(int x)
{
    if(x != father[x])
    {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
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

bool IsTree(int n_max)
{
    int rootnum = 0;
    int in_num = 0;//入度为0的结点个数
    for(int i=1; i<=n_max; i++)
    {
        if(tag[i] == 1)
        {
            if(indegree[i] > 1)
                return false;
            else if(indegree[i] == 0)
                in_num ++;
            if(father[i] == i)
                rootnum ++;
        }
    }
    if(in_num == 1 && rootnum == 1)
        return true;
    if(in_num == 0 && rootnum == 0)
        return true;//空集也是树
    return false;
}

int main()
{
    int from,to;
    while(cin >> from >> to)//每组输入的第一个数据
    {
        if(from == -1 && to == -1)
        {
            break;
        }
        else if(from == 0 && to == 0)//当前组组输入结束
        {
            if(IsTree(n_max))
                cout << "Case " << input_num << " is a tree." << endl;
            else
                cout << "Case " << input_num << " is not a tree." << endl;

            input_num ++;
            initial();//初始化
            n_max = 0;
        }
        else//输入本组内剩下数据
        {

            n_max = max(from,n_max);
            n_max = max(to,n_max);
            Union(from,to);
            indegree[to] ++;
            tag[from] = 1;
            tag[to] = 1;
        }
    }
    return 0;
}
