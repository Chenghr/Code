#include <stdio.h>
#include <stdlib.h>
/*
//旋转数组内不存在重复元素
int findMin(int* a, int numsSize)
{
    int left = 0,right = numsSize-1;
    int mid;
    if(a[right] >= a[left]) return a[left];//数组未旋转
    while(left <= right)
    {
        mid = (left + right) /2;
        if(a[mid] > a[mid+1]) return a[mid+1];//找到了旋转交界点
        else if(a[mid-1] > a[mid]) return a[mid];//找到了旋转交界点
        else if(a[mid] > a[0]) left = mid+1;//旋转交界点在右侧
        else right = mid-1;//旋转交界点在左侧
    }
    return -1;
}
*/
//旋转数组内存在重复元素
int findMin(int* a, int numsSize)
{
    int left = 0,right = numsSize-1;
    int mid;
    if(a[right] > a[left]) return a[left];//数组未旋转
    while(left < right)
    {
        mid = (left + right) /2;
        if(a[mid] > a[right]) left = mid+1;
        else if(a[mid] < a[right]) right = mid;
        else right--;
    }
    return a[left];
}

int main()
{
    int a[] = {3,1};
    int min;
    min = findMin(a,2);
    printf("%d",min);
    return 0;
}
