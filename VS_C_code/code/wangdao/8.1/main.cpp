#include <iostream>

using namespace std;

int n;
int **a;

int yanghui(int i,int j)//求i行j列的值
{
    if(i == 0 || i < j) return 0;
    else if(i == j) return 1;
    else if (j == 0) return 1;
    else return yanghui(i-1,j-1)+yanghui(i-1,j);
}

int main()
{
    while (cin >> n)
    {
        a = new int *[n];//动态创建二维数组
        for (int i=0; i<n; i++)
        {
            a[i] = new int [n];
        }

        for(int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                a[i][j] = yanghui(i,j);
            }
        }

        for(int i=1; i<n; i++)
        {
            for (int j=0; j<n-1; j++)
            {
                if(a[i][j] == 0)
                {
                    cout << "  ";
                }
                else cout << a[i][j] << " ";
            }
            if(a[i][n-1] == 0)
                {
                    cout << " " << endl;;
                }
                else cout << a[i][n-1] << " ";
        }
    }
    return 0;
}
