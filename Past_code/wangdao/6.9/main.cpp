/**
�ؼ����ڵ�ʽ root(x*y,k) = root(root(x,k)*root(y,k),k)
������������ root(x^111,k) = root(root(x^100,k)*root(x^10,k)*root(x,k),k)
               ���� root(x^100,k) = root(root(x^10)*root(x^10),k)
                       root(x^10,k) = root(root(x,k)*root(x,k),k)
                    ������Ϊ�����Ʊ�ʾ��
�������ƶ������� ֻ�Ǵ�����root������
**/
#include <iostream>

using namespace std;

int root(int N,int k)
{
    if(N >= k)
    {
        int num = 0;
        while(N != 0)
        {
            num += N%k;
            N /= k;
        }
        return root(num,k);
    }
    else
    {
        return N;
    }
}

int get(int x, int y, int k)
{
    int temp = root(x,k);
    int rtn = 1;
    while(y > 0)//���ƿ����ݵ�˼�룬����������
    {
        if(y%2 == 1)
        {
            rtn = root(rtn*temp,k);//root(x*y,k) = root(root(x,k)*root(y,k),k)
        }
        temp = root(temp*temp,k);
        y /= 2;
    }
    return rtn;
}

int main()
{
    int x,y,k;
    while(cin >> x >> y >> k)
    {
        cout << get(x,y,k) << endl;
    }
    return 0;
}
