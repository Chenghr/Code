#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int x,int y)
{
    return x>y;
}

int main()
{
    int a[10];
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9])
    {
        sort(a,a+10,compare);//��д�ȽϺ������Ӵ�С����
        for(int i=0; i<10;i++)//ż���Ӵ�С���
        {
            if(a[i]%2 == 1)
            {
                cout << a[i] << " ";
            }
        }

        sort(a,a+10);//Ĭ�ϴ�С��������
        for(int i=0; i<10;i++)//ż����С�������
        {
            if(a[i]%2 == 0)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
