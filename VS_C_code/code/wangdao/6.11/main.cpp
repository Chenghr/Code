#include <iostream>

using namespace std;

/**
递归的时间复杂度太高
int getk(int k)
{
    if(k == 0) return a0%10000;
    else if(k == 1) return a1%10000;
    else return (p*getk(k-1)%10000+q*getk(k-2)%10000)%10000;
}
**/
//循环的时间复杂度低一些

int main()
{
    int a0,a1,p,q,k;
    while(cin >> a0 >> a1 >> p >> q >> k)
    {
        if(k == 0)
        {
            cout << a0%10000 << endl;
        }
        else if(k == 1)
        {
            cout << a1%10000 << endl;
        }
        else
        {
            int a = p*a1%10000+q*a0%10000;
            int i = 2;
            while(i <= k)
            {
                a0 = a1%10000;
                a1 = a%10000;
                a = p*a1+q*a0;
                i++;
            }
            cout << a1%10000 << endl;
        }
    }
    return 0;
}
