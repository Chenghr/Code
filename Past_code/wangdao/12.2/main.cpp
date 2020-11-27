#include <iostream>

using namespace std;

void getsum(int a[], int sum[], int n)
{
    sum[0] = a[0];
    for(int i=1; i<n; i++)
    {
        sum[i] = ((sum[i-1]+a[i] > a[i])) ? (sum[i-1]+a[i]) : a[i];
    }
}

void output(int a[], int sum[], int n)
{
    int maxsum = sum[0];
    int l = 0;
    for(int i=0; i<n; i++)
    {
        if(sum[i] > maxsum)
        {
            maxsum = sum[i];
            l = i;
        }
    }
    int i=0;
    for( i=l; i>=0; i--)
    {
        maxsum -= a[i];
        if(maxsum == 0) break;
    }
    cout << sum[l] << " " << a[i] << " " << a[l] << endl;
}

int main()
{
    int a[10001] = {0};
    int sum[10001] = {0};//辅助数组
    int n;
    while (cin >> n)
    {
        if(n == 0) break;

        int tag = 0;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            if(a[i] >= 0) tag = 1;//元素非全负
        }

        if(tag == 0)//全负
        {
            cout << 0 << endl;
            continue;
        }

        getsum(a,sum,n);
        output(a,sum,n);

    }
    return 0;
}
