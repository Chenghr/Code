#include <stdio.h>
#include <stdlib.h>

int majorityElement(int *a,int asize)
{
    int curnum = a[0];
    int count = 1;
    int i;
    for(i=1;i<asize;i++)
    {
        if(count==0)
        {
            curnum = a[i];
            count = 1;
        }
        else
        {
            if(a[i]==curnum)count++;
            else count--;
        }
    }//一遍遍历结束后，保存的curnum为数组中出现次数最多的元素
    return curnum;
}


//分治法，分别求出左边和右边的众数，然后全局遍历一次即可

int countinrange(int *a,int num,int left,int right)
{
    int count = 0;
    int i = 0;
    for(i=left;i<right+1;i++)
    {
        if(a[i]==num)count++;
    }
    return count;
}

int findmajorityElement(int *a,int left,int right)
{
    int mid = (right-left)/2 +left;
    int lmajor,rmajor;
    int lcount,rcount;

    //仅有一个元素
    if(left==right) return a[left];

    //分别计算左右众数
    lmajor = findmajorityElement(a,left,mid);
    rmajor = findmajorityElement(a,mid+1,right);

    //左右众数相等时直接返回
    if(lmajor==rmajor) return lmajor;

    //左右众数不等时，选出赢家返回给上层
    lcount = countinrange(a,lmajor,left,right);
    rcount = countinrange(a,rmajor,left,right);
    return lcount > rcount ? lmajor : rmajor;
}

int majorityElement(int *a,int asize)
{
    return findmajorityElement(a,0,asize-1);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
