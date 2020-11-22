#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n=0;
    while (scanf("%d",&n) != EOF )
    {
        int x,y,z;
        for(x=0; x<=100; x++)
        {
            for(y=0; y<=100; y++)
            {
                z = 100-x-y;
                if(5*x+3*y+z/3 < n)
                {
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
                }
            }
        }
    }
    return 0;
}
