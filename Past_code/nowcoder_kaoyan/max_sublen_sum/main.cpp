#include <iostream>

using namespace std;


int GetMaxSublen(int a[],int n)
{
    int *s = new int[n];
    for(int i=0; i<n; i++)
    {
        s[i] = 0;
    }
    s[0] = a[0];
    for(int i=1; i<n; i++)
    {
        if(s[i-1]+a[i] < a[i])
        {
            s[i] = a[i];
        }
        else
        {
            s[i] = s[i-1]+a[i];
        }
    }

    int maxsub = s[0];
    for(int i=0; i<n; i++)
    {
        if(s[i] > maxsub) maxsub = s[i];
    }
    return maxsub;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int *a = new int[n];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        cout << GetMaxSublen(a,n) << endl;
    }
    return 0;
}
