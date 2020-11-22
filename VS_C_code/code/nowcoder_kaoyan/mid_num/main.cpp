#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[10001] = {0};
    int n;
    while(cin >> n)
    {
        if(n == 0) break;

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);

        if(n%2 == 1)
        {
            cout << a[n/2] << endl;
        }
        else
        {
            cout << (a[n/2]+a[n/2-1])/2 << endl;
        }
    }
    return 0;
}
