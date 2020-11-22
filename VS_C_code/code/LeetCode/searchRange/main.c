#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* a, int asize, int target, int* returnSize)
{
    int left = 0,right = asize;
    int mid;
    int *result;
    result = (int *)malloc(2*sizeof(int));
    result[0] = -1;
    result[1] = -1;
    returnSize[0] = 2;//c语言数组长度未知，所以要返回数组长度信息

    while(left<right)//搜索左侧边界，由于right = asize ，所以循环条件为 left < right
    {
        mid = left + (right - left) / 2;//可以避免mid溢出
        if(a[mid] == target)//不停止，继续向左逼近
        {
            right = mid;
        }
        else if(a[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }
    if(left!=asize && a[left] == target) //找到左侧边界
    {
        result[0] = left;
    }

    left = 0;
    right = asize;
    while(left<right)//搜索右侧边界
    {
        mid = left + (right - left) / 2;//可以避免mid溢出
        if(a[mid] == target)//不停止，继续向右逼近
        {
            left = mid+1;
        }
        else if(a[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }

    if(right != 0 && a[right-1] == target)
    {
        result[1] = right-1;//找到右侧边界
    }

    return result;
}

int main()
{
    int a[] = {5,7,7,8,8,10};
    int *b;
    b = searchRange(a,6,8,b);
    printf("%d ",b[0]);
    printf("%d ",b[1]);
    return 0;
}
