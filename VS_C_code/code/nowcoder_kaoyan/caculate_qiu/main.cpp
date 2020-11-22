#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int x0,y0,z0,x1,y1,z1;
    while(cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1)
    {
        double x = abs(x0-x1);
        double y = abs(y0-y1);
        double z = abs(z0-z1);
        double r = sqrt(x*x+y*y+z*z);
        double pi = acos(-1);
        double v = 4.0/3.0*pi*r*r*r;

        printf("%.3lf %.3lf\n",r,v);
    }
    return 0;
}
