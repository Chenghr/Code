#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *a, int asize, int *b, int bsize)
{
    int i,j,imin,imax;
    int maxleft,minright;

    //先确保i在较小的数组中查找，设a为较小的那个数组
    if(asize>bsize)
    {
        return findMedianSortedArrays(b,bsize,a,asize);
    }

    //在a中搜索i，并根据i确定j
    imin = 0;
    imax = asize;
    while(imin <= imax)
    {
        //确定i，j
        i = imin + (imax-imin)/2;
        j = (asize+bsize+1)/2 - i;

        //判定条件
        if(i>imin&&a[i-1]>b[j])//i过大，且i-1>=imin
        {
            imax = i-1;
        }
        else if(i<imax&&a[i]<b[j-1])//i过小，且i+1<=imax
        {
            imin = i+1;
        }
        else//找到了我们需要的i
        {
            //先找左边部分的最大值
            if(i==0)//先处理一些特殊情况
            {
                maxleft = b[j-1];//a[i-1]不存在
            }
            else if(j==0)
            {
                maxleft = a[i-1];//b[j-1]不存在
            }
            else
            {
                if(a[i-1]>b[j-1]) maxleft = a[i-1];
                else maxleft = b[j-1];
            }

            //若数组总个数为奇数，则不用继续计算下去，直接返回左侧最大数即可
            if( (asize+bsize)%2 == 1) return maxleft;

            //数组总个数为偶数时，则要寻找右边部分的最小值
            if(i == asize)
            {
                minright = b[j];//a[i]不存在
            }
            else if(j == bsize)
            {
                minright = a[i];//b[j]不存在
            }
            else
            {
                if(a[i]<b[j]) minright = a[i];
                else minright = b[j];
            }

            return (maxleft+minright)/2.0;//除以2.0确保返回的是double型变量
        }
    }
    return 0.0;
}

int main()
{
    int a[] = {1,3};
    int b[] = {2};
    double f;
    f = findMedianSortedArrays(a,2,b,1);
    printf("%lf",f);
    return 0;
}
