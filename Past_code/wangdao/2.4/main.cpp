#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        char **a = new char *[n];//������̬��ά����
        for (int i=0; i<n; i++)
        {
            a[i] = new char [n];
        }

        for(int i=0; i<n; i++)//�������ģ��
        {
            for (int j=0; j<n; j++)
            {
                cin >> a[i][j];
            }
            getchar();
        }

        int q;
        cin >> q;



    }
    return 0;
}
