#include <iostream>
#include <cmath>

using namespace std;

int getnum(int n)
{
    int num = 0;
    int m = sqrt(n);
    for(int i=1; i<=m; i++)
    {
        if(n%i == 0) num += 2;
    }
    if(m*m == n) num--;//这个时候会多加了一个
    return num;
}

int main()
{
    int a[1001];
    int n;
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        for(int i=0; i<n; i++)
        {
            cout << getnum(a[i]) << endl;
        }
    }
    return 0;
}
