#include <iostream>

using namespace std;

struct ant
{
    int point;
    int v;
    int tag;//�Ƿ�Ϊ����A
};

int main()
{
    int n;
    cin >> n;//��������

    ant *ants = new ant [n];
    for(int i=0; i<n; i++)
    {
        cin >> ants[i].point >> ants[i].v;
        if(ants[i].v == 0) ants[i].tag = 1;
        else ants[i].tag = 0;
    }

    for(int i=0; i<n; i++)//��λ������
    {
        for(int j=i+1; j<n; j++)
        {
            if(ants[i].point > ants[j].point)
            {
                ant temp = ants[i];
                ants[i] = ants[j];
                ants[j] = temp;
            }
        }
    }

    int pos = 0;//����A��λ��
    for(pos=0; pos<n; pos++)
    {
        if(ants[pos].v == 0) break;
    }

    int lr = 0,rl = 0;//λ��A��������ߵģ��Լ�λ��A�Ҳ������ߵ�
    for(int i=0; i<n; i++)
    {
        if(i<pos && ants[i].v == 1) lr++;
        if(i>pos && ants[i].v == -1) rl++;
    }

    if(lr == rl)
    {
        cout << "Cannot fall!" << endl;
    }
    else if(lr > rl)
    {
        int t = lr-rl;
        int i=0;
        for(i=0; i<pos; i++)//�ҵ���A�ٶȵ��Ǹ�����
        {
            if(ants[i].v == 1) t--;
            if(t == 0) break;
        }
        cout << 100-ants[i].point << endl;
    }
    else
    {
        int t = rl-lr;
        int i=0;
        for(i=n-1; i>pos; i--)//�ҵ���A�ٶȵ��Ǹ�����
        {
            if(ants[i].v == -1) t--;
            if(t == 0) break;
        }
        cout << ants[i].point << endl;
    }
    return 0;
}
