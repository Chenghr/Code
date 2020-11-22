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
    for(int i=0; i<=n; i++)//����±��1��ʼ
    {
        father[i] = i;
        height[i] = 1;
    }
}

int Find(int x)//���Ҹ��ڵ�
{
    if(father[x] != x)
    {
        father[x] = Find(father[x]);//·��ѹ��
    }
    return x;
}

void Union(int x, int y)//�ϲ����
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
    initial(n);//��ʼ��
    for(int i=1; i<=n; i++)//��ͨͼ
    {
        if(i != x)//�ߵĳ�����ɾ��x
        {
            for(int j=0; j<edge[i].size(); j++)
            {
                if(edge[i][j] != x)//�ߵĵ����ɾ��x
                {
                    Union(i,edge[i][j]);
                }
            }
        }
    }

    int num = 0;//��ͨ������Ŀ
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

    int n;//������Ŀ
    fin >> n;

    int from,to;//��ȡ��
    while (!fin.eof())
    {
        fin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    int tag = 0;//����Ƿ��н�
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
        cout << "����������Ҫ��Ķ��㣡" << endl;

    return 0;
}
