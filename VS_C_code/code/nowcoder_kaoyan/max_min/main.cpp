#include <iostream>
#include<algorithm>

using namespace std;
const int MAXN = 10001;

int main()
{
    int a[MAXN];
    int n;
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        cout << a[n-1] << " " << a[0] << endl;
    }
    return 0;
}
