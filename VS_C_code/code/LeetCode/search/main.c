#include <stdio.h>
#include <stdlib.h>

//旋转数组1，数组内无重复元素
int search(int* a, int aSize, int target)
{
    int left = 0,right = aSize-1;
    int mid;
    while(left<=right)
    {
        mid = (left + right) / 2;
        if(a[mid] == target) return mid;
        else if(a[mid]>=a[left])//左半部分有序,这里要>=，避免mid==left的情况
        {
            if(a[left]<=target&&a[mid]>target)//目标在左半区间内
            {
                right = mid-1;
            }
            else//舍弃左半部分
            {
                left = mid+1;
            }
        }
        else//右半部分有序
        {
            if(a[mid]<target&&a[right]>=target)//目标在右半区间内
            {
                left = mid+1;
            }
            else//舍弃右半部分
            {
                right = mid-1;
            }
        }
    }
    return -1;
}


//旋转数组2，数组内有重复元素
bool search(int* a, int aSize, int target)
{
    int left = 0,right = aSize-1;
    int mid;
    while(left<=right)
    {
        mid = (left + right) / 2;
        if(a[mid] == target) return true;
        else if(a[mid] == a[left]) left++;//相同时左侧缩进一个单位
        else if(a[mid] == a[right]) right--;//相同时右侧缩进一个单位，最坏情况下是O(n);
        else if(a[mid]>a[left])//左半部分有序,这里要>=，避免mid==left的情况
        {
            if(a[left]<=target&&a[mid]>target)//目标在左半区间内
            {
                right = mid-1;
            }
            else//舍弃左半部分
            {
                left = mid+1;
            }
        }
        else//右半部分有序
        {
            if(a[mid]<target&&a[right]>=target)//目标在右半区间内
            {
                left = mid+1;
            }
            else//舍弃右半部分
            {
                right = mid-1;
            }
        }
    }
    return false;
}

int main()
{
    int a[2] = {3,1};
    int result;
    result = search(a,2,1);
    printf("%d",result);
    return 0;
}
