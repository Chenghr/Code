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

        char **a = new char *[n];//创建动态二维数组
        for (int i=0; i<n; i++)
        {
            a[i] = new char [n];
        }

        for(int i=0; i<n; i++)//输入基本模板
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
