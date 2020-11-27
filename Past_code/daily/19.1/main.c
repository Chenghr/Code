#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int low,int high)//一趟快排
{
    int i=low,j=high;
    int pos = low;//第一个数当做基准点
    int temp;

    while (i != j)
    {
        while(i<j && a[j] > a[pos])
        {
            j--;//从右向左找出第一个比基准点小的数
        }
        while(i<j && a[i] < a[pos])
        {
            i++;//从左到右找出第一个比基准点大的数
        }

        temp = a[i];//交换
        a[i] = a[j];
        a[j] = temp;
    }

    temp = a[i];//交换基准点与相遇点
    a[i] = a[pos];
    a[pos] = temp;
    return i;//返回基准点坐标
}

void quicksort(int a[],int low,int high)//快排
{
    int mid;
    if(low < high)//区间内有多个元素时
    {
        mid = partition(a,low,high);//一趟划分
        quicksort(a,low,mid);//左半部分递归排序
        quicksort(a,mid+1,high);//右半部分递归排序
    }
}

int main()
{
    int n;
    int a[8] = {0};
    int i,j;
    scanf("%d", &n);//输入几组数据
    for(i=0; i<n; i++)//共n组
    {
        for (j=0; j<8; j++)//每组都是8个数据
        {
            scanf("%d", &a[j]);//循环输入数组数据
        }

        quicksort(a,0,7);

        for(j=0; j<7; j++)
        {
            printf("%d ",a[j]);
        }
        printf("%d\n",a[7]);//输出最后一个元素，要换行
    }
    return 0;
}
