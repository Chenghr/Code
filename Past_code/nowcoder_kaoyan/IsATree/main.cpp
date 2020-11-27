#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10001;

int father[MAXN];//���ڵ�
int height[MAXN];
int indegree[MAXN];//��ǰ������
int tag[MAXN];//��ǽ���Ƿ���ֹ�
int n_max;//��ǳ��ֵĽ��������
int input_num = 1;

vector<int> edge[MAXN];//�洢��

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
    int in_num = 0;//���Ϊ0�Ľ�����
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
        return true;//�ռ�Ҳ����
    return false;
}

int main()
{
    int from,to;
    while(cin >> from >> to)//ÿ������ĵ�һ������
    {
        if(from == -1 && to == -1)
        {
            break;
        }
        else if(from == 0 && to == 0)//��ǰ�����������
        {
            if(IsTree(n_max))
                cout << "Case " << input_num << " is a tree." << endl;
            else
                cout << "Case " << input_num << " is not a tree." << endl;

            input_num ++;
            initial();//��ʼ��
            n_max = 0;
        }
        else//���뱾����ʣ������
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
