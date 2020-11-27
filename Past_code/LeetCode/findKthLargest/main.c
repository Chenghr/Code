#include <stdio.h>
#include <stdlib.h>


int partition(int *a,int low,int high)//快排的一趟划分
{
    int i = low,j = high;
    int pivot = a[low];//选取第一个元素作为基准点
    int temp=0;
    while (i!=j)
    {
        while(i<j&&a[j]<pivot+1)j--;//从右向左找到第一个比基准点大的元素
        while(i<j&&a[i]>pivot-1)i++;//从左向右找到第一个比基准点小的元素
        //交换a[i]与a[j]位置
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    //交换a[i]与基准点
    temp = a[low];
    a[low] = a[i];
    a[i] = temp;
    return i;//返回基准点所在数组下标
}

int quickselect(int *a,int low,int high,int k)
{
    int mid = -1;
    if(low<high)//区间内有多个元素
    {
        mid = partition(a,low,high);//找出划分点的下标
        if(mid == k-1)//恰好分割位为所找位置
        {
            return a[mid];
        }
        else if (mid < k-1)//要找位置在分割点右侧
        {
            return quickselect(a,mid+1,high,k);
        }
        else//要找位置在分割点左侧
        {
            return quickselect(a,low,mid-1,k);
        }
    }
    else//区间内仅有一个元素
    {
        return a[low];
    }
}

int findKthLargest(int *a, int asize, int k)
{
    return quickselect(a,0,asize-1,k);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
