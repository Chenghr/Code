#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Mouse
{
    int weight;
    string hatcolor;
};

bool comp(Mouse x,Mouse y)
{
    return x.weight > y.weight;
}

int main()
{
    int n;
    while (cin >> n)
    {
        Mouse *m = new Mouse [n];
        getchar();
        for (int i=0; i<n; i++)
        {
            cin >> m[i].weight >> m[i].hatcolor;
            getchar();
        }

        sort(m,m+n,comp);

        for(int i=0;i<n;i++)
        {
            cout << m[i].hatcolor << endl;
        }
    }
    return 0;
}
