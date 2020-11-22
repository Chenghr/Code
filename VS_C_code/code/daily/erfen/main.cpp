#include <iostream>

using namespace std;

//�������ֲ���
int binarySearch(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target �����
        if (target > nums[mid])
            right = mid - 1;
        //target ���ұ�
        else if (target < nums[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

//----------�����Ƕ��ֲ��ҵ�6�ֱ������-------------

//�ҵ�һ������target��Ԫ��λ�� ���ű�����<
int findFirstGreater(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target �����
        if (target < nums[mid])
            right = mid - 1;
        //target ���ұ�
        else
            left = mid + 1;

    }
    return left;
}

// ���ҵ�һ�����ڵ���target��Ԫ��λ�� ������<= ��֤ left��ָ��target�Ļ���
int findFirstGreaterEqual(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target ����� ������ target> nums[mid]
        if (target <= nums[mid])
            right = mid - 1;
        //target ���ұ�
        else
            left = mid + 1;

    }
    return left;
}

//���ҵ�һ������target��Ԫ��λ�� ������<=

int findFirstEqual(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target �����
        if (target <= nums[mid])
            right = mid - 1;
        //target ���ұ�
        else
            left = mid + 1;

    }
    //�жϱ߽�
    if (left < nums.length && nums[left] == target)
        return left;
    return -1;
}


//�������һ��=target��Ԫ��λ�� ������<
int findLastEqual(int[] nums, int n, int target)
{

    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target �����
        if (target < nums[mid])
            right = mid - 1;
        //target ���ұ�
        else
            left = mid + 1;

    }
    if (right >= 0 && nums[right] == target)
        return right;
    return -1;

}

//�������һ��<target��Ԫ��λ�� <=

int findLastLess(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target �����
        if (target <= nums[mid])
            right = mid - 1;
        //target ���ұ�
        else
            left = mid + 1;

    }
    return right;
}

//�������һ��<=target��Ԫ��λ�� <

int findLastLessEqual(int[] nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    //���������� <=
    while (left <= right)
    {
        mid = left + (right-left) / 2;
        //target �����
        if (target < nums[mid])
            right = mid - 1;
        //target ���ұ�
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
