#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize-1;
    int mid;

    //先处理特殊情况
    if(nums[0] > target) return 0;
    else if(nums[numsSize-1] < target) return numsSize;

    while(left<=right)
    {
        mid = left + (right - left)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    //未找到，返回插入后下标
    if(nums[left] < target) return left+1;
    else return left;
}

int main()
{
    int a[] = {1,3,5,6};
    int tag;
    tag = searchInsert(a,4,2);
    printf("%d",tag);
    return 0;
}
