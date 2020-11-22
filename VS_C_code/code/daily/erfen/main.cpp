#include <iostream>

using namespace std;

//基础二分查找
int binarySearch(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边
        if (target > nums[mid])
            right = mid - 1;
        //target 在右边
        else if (target < nums[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

//----------以下是二分查找的6种变体情况-------------

//找第一个大于target的元素位置 符号必须是<
int findFirstGreater(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边
        if (target < nums[mid])
            right = mid - 1;
        //target 在右边
        else
            left = mid + 1;

    }
    return left;
}

// 查找第一个大于等于target的元素位置 符号是<= 保证 left有指向target的机会
int findFirstGreaterEqual(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边 条件是 target> nums[mid]
        if (target <= nums[mid])
            right = mid - 1;
        //target 在右边
        else
            left = mid + 1;

    }
    return left;
}

//查找第一个等于target的元素位置 符号是<=

int findFirstEqual(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边
        if (target <= nums[mid])
            right = mid - 1;
        //target 在右边
        else
            left = mid + 1;

    }
    //判断边界
    if (left < nums.length && nums[left] == target)
        return left;
    return -1;
}


//查找最后一个=target的元素位置 符号是<
int findLastEqual(int[] nums, int n, int target)
{

    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边
        if (target < nums[mid])
            right = mid - 1;
        //target 在右边
        else
            left = mid + 1;

    }
    if (right >= 0 && nums[right] == target)
        return right;
    return -1;

}

//查找最后一个<target的元素位置 <=

int findLastLess(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边
        if (target <= nums[mid])
            right = mid - 1;
        //target 在右边
        else
            left = mid + 1;

    }
    return right;
}

//查找最后一个<=target的元素位置 <

int findLastLessEqual(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //条件必须是 <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target 在左边
        if (target < nums[mid])
            right = mid - 1;
        //target 在右边
        else
            left = mid + 1;

    }
    return right;
}
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
