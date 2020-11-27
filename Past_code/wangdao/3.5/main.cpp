#include <iostream>
#include <algorithm>

using namespace std;

struct num
{
    int num1;
    int num2;
};

bool comp(num x,num y)
{
    if(x.num1 == y.num1) return x.num2 <y.num2;
    else return x.num1 <y.num1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        num *a = new num [n];
        for (int i=0; i<n; i++)
        {
            cin >> a[i].num1 >> a[i].num2;
        }

        sort(a,a+n,comp);

        cout << a[0].num1 << " " << a[0].num2 << endl;
    }
    return 0;
}
