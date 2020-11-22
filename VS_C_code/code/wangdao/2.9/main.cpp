#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int p,t,g1,g2,g3,gj;
    double result;
    while (cin >> p >> t >> g1 >> g2 >> g3 >> gj)
    {
        if(abs(g1-g2) <= t)
        {
            result = (g1+g2)/2.0;
            printf("%.1lf",result);
        }
        else
        {
            int x1 = abs(g3-g1);
            int x2 = abs(g3-g2);
            if(x1 <= t && x2 <= t)
            {
                if(g1 > g2 && g1 > g3) result = g1;
                else if (g2 > g1 && g2 > g3) result = g2;
                else result = g3;
                printf("%.1lf",result);
            }
            else if (x1>t && x2>t)
            {
                result = gj;
                printf("%.1lf",result);
            }
            else
            {
                if(g1 > g2)
                {
                    result = (g1+g3)/2.0;
                    printf("%.1lf",result);
                }
                else
                {
                    result = (g2+g3)/2.0;
                    printf("%.1lf",result);
                }
            }
        }
    }
    return 0;
}
