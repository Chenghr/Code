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
    returnSize[0] = 2;//c�������鳤��δ֪������Ҫ�������鳤����Ϣ

    while(left<right)//�������߽磬����right = asize ������ѭ������Ϊ left < right
    {
        mid = left + (right - left) / 2;//���Ա���mid���
        if(a[mid] == target)//��ֹͣ����������ƽ�
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
    if(left!=asize && a[left] == target) //�ҵ����߽�
    {
        result[0] = left;
    }

    left = 0;
    right = asize;
    while(left<right)//�����Ҳ�߽�
    {
        mid = left + (right - left) / 2;//���Ա���mid���
        if(a[mid] == target)//��ֹͣ���������ұƽ�
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
        result[1] = right-1;//�ҵ��Ҳ�߽�
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
