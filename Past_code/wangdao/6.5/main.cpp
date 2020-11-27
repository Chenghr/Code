#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a,int b)//欧几里得算法求得最大公约数
{
    if(b == 0) return a;
    else return GCD(b,a%b);
}

int main()
{
    int n;
    int a[601];
    while(cin >> n)
    {
        if(n == 0) break;

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        sort(a,a+n);

        int num = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(GCD(a[i],a[j]) == 1) num ++;
            }
        }

        cout << num << endl;
    }
    return 0;
}
