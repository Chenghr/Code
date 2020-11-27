#include <stdio.h>
#include <stdlib.h>
/*
//��ת�����ڲ������ظ�Ԫ��
int findMin(int* a, int numsSize)
{
    int left = 0,right = numsSize-1;
    int mid;
    if(a[right] >= a[left]) return a[left];//����δ��ת
    while(left <= right)
    {
        mid = (left + right) /2;
        if(a[mid] > a[mid+1]) return a[mid+1];//�ҵ�����ת�����
        else if(a[mid-1] > a[mid]) return a[mid];//�ҵ�����ת�����
        else if(a[mid] > a[0]) left = mid+1;//��ת��������Ҳ�
        else right = mid-1;//��ת����������
    }
    return -1;
}
*/
//��ת�����ڴ����ظ�Ԫ��
int findMin(int* a, int numsSize)
{
    int left = 0,right = numsSize-1;
    int mid;
    if(a[right] > a[left]) return a[left];//����δ��ת
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
