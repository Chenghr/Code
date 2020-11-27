#include <stdio.h>
#include <stdlib.h>

//��ת����1�����������ظ�Ԫ��
int search(int* a, int aSize, int target)
{
    int left = 0,right = aSize-1;
    int mid;
    while(left<=right)
    {
        mid = (left + right) / 2;
        if(a[mid] == target) return mid;
        else if(a[mid]>=a[left])//��벿������,����Ҫ>=������mid==left�����
        {
            if(a[left]<=target&&a[mid]>target)//Ŀ�������������
            {
                right = mid-1;
            }
            else//������벿��
            {
                left = mid+1;
            }
        }
        else//�Ұ벿������
        {
            if(a[mid]<target&&a[right]>=target)//Ŀ�����Ұ�������
            {
                left = mid+1;
            }
            else//�����Ұ벿��
            {
                right = mid-1;
            }
        }
    }
    return -1;
}


//��ת����2�����������ظ�Ԫ��
bool search(int* a, int aSize, int target)
{
    int left = 0,right = aSize-1;
    int mid;
    while(left<=right)
    {
        mid = (left + right) / 2;
        if(a[mid] == target) return true;
        else if(a[mid] == a[left]) left++;//��ͬʱ�������һ����λ
        else if(a[mid] == a[right]) right--;//��ͬʱ�Ҳ�����һ����λ����������O(n);
        else if(a[mid]>a[left])//��벿������,����Ҫ>=������mid==left�����
        {
            if(a[left]<=target&&a[mid]>target)//Ŀ�������������
            {
                right = mid-1;
            }
            else//������벿��
            {
                left = mid+1;
            }
        }
        else//�Ұ벿������
        {
            if(a[mid]<target&&a[right]>=target)//Ŀ�����Ұ�������
            {
                left = mid+1;
            }
            else//�����Ұ벿��
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
