#include <iostream>

using namespace std;

int main()
{
    int a0,a1,p,q,k;
    while(cin >> a0 >> a1 >> p >> q >> k)
    {
        if(k == 0)
        {
            cout << a0%10000 << endl;
            continue;
        }
        if(k == 1)
        {
            cout << a1%10000 << endl;
            continue;
        }

        for(int i=2; i<=k; i++)
        {
            int a = (a1*p)%10000+(a0*q)%10000;
            a0 = a1;
            a1 = a%10000;
        }
        cout << a1 << endl;
    }
    return 0;
}
