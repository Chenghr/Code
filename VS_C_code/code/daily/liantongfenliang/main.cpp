#include <iostream>

using namespace std;

const int MAXN = 101;

int father[MAXN];//���游�׽����±�
int height[MAXN];//���߶�

void initial(int n)//��ʼ������
{
    for(int i=0; i<n; i++)
    {
        father[i] = i;//��־���Ϊ�����Ľ��
        height[i] = 1;
    }
}

int Find(int x)//����x�ĸ����
{
    if(father[x] != x)
    {
        father[x] = Find(father[x]);//·��ѹ���������´β��Ҵ���
    }
    return x;
}

void Union(int x, int y)//�ϲ����
{
    x = father[x];
    y = father[y];

    if(x != y)//x��y������ͬһ��ͨ����ʱ
    {
        if(height[x] > height[y])//���߶ȵ͵Ľ��ϲ������߶ȸߵĽ��
        {
            father[y] = x;
        }
        else if(height[x] < height[y])
        {
            father[x] = y;
        }
        else//���߶���ͬ�������߶���1
        {
            father[y] = x;
            height[x] += 1;
        }
    }
}

int main()
{
    int n,m;//������Լ��ߵ���Ŀ
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
