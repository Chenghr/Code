#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int len;
    while(cin >> len)
    {
        int a[10001];
        for(int i=0; i<=len; i++)//³õÊ¼»¯
        {
            a[i] = 1;
        }

        int m;
        cin >> m;
        for(int i=0; i<m; i++)
        {
            int from,to;
            cin >> from >> to;
            for(int j=from; j<=to; j++)
            {
                a[j] = 0;
            }
        }

        int sum = 0;
        for(int i=0; i<=len; i++)
        {
            if(a[i] == 1) sum++;
        }
        cout << sum << endl;
    }
    return 0;
}
