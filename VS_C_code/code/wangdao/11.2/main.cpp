#include <iostream>

using namespace std;

const int maxn = 1000000;
int father[maxn];
int height[maxn];
int tag[maxn];

void initial()//��ʼ��
{
    for (int i=0; i<maxn; i++)
    {
        father[i] = i;
        height[i] = 0;
        tag[i] =0;
    }
}

int findroot(int x)//���Ҹ��ڵ�
{
    if(x != father[x])
    {
        father[x] = findroot(father[x]);//·��ѹ��
    }
    return father[x];
}

void Union(int x, int y)//�ϲ�����
{
    x = findroot(x);//�ҵ����Եĸ����
    y = findroot(y);

    if(x != y)//����һ��������
    {
        if(height[x] < height[y])//������Ϊ����������
        {
            father[x] = y;
        }
        else if(height[y] < height[x])
        {
            father[y] = x;
        }
        else//�������߶���ͬ������·��ѹ����һ���������߶�Ϊ2�����Ա���ӵ����߶ȼ�һ����
        {
            father[y] = x;
            height[x] ++;
        }
    }

    return ;
}

int main()
{
    initial();//��ʼ��

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
