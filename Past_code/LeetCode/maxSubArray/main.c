#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* a, int aSize)
{
    int max=a[0];
    int curmax=a[0];
    int i;
    for(i=1;i<aSize;i++)
    {
        if(a[i]>curmax+a[i]) curmax = a[i];
        else curmax = curmax+a[i];
        if(curmax>max) max=curmax;
    }
    return max;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
