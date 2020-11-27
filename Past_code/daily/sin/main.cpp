#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int x;
    while(cin >> x)
    {
        double result = 0;
        double k = x;
        int sig = 1;
        int a = 1;

        while(k > 1e-7)
        {
            result += k*sig;

            sig *= -1;
            k = k*x*x/(a+1)/(a+2);
            a += 2;
        }

        printf("%.7lf\n",result);
    }
    return 0;
}
