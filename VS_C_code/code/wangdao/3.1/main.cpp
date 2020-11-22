#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int a[1000] = {0};
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        if(n == 1)
        {
            cout << a[0] << endl << -1 << endl;
        }
        else
        {
            sort(a,a+n);//默认从小到大排序
            cout << a[n-1] << endl;
            for(int i=0; i<n-2; i++)
            {
                cout << a[i] << " ";
            }
            cout << a[n-2] << endl;
        }
    }
    return 0;
}
