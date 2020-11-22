#include <stdio.h>
#include <stdlib.h>


int partition(int *a,int low,int high)//���ŵ�һ�˻���
{
    int i = low,j = high;
    int pivot = a[low];//ѡȡ��һ��Ԫ����Ϊ��׼��
    int temp=0;
    while (i!=j)
    {
        while(i<j&&a[j]<pivot+1)j--;//���������ҵ���һ���Ȼ�׼����Ԫ��
        while(i<j&&a[i]>pivot-1)i++;//���������ҵ���һ���Ȼ�׼��С��Ԫ��
        //����a[i]��a[j]λ��
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    //����a[i]���׼��
    temp = a[low];
    a[low] = a[i];
    a[i] = temp;
    return i;//���ػ�׼�����������±�
}

int quickselect(int *a,int low,int high,int k)
{
    int mid = -1;
    if(low<high)//�������ж��Ԫ��
    {
        mid = partition(a,low,high);//�ҳ����ֵ���±�
        if(mid == k-1)//ǡ�÷ָ�λΪ����λ��
        {
            return a[mid];
        }
        else if (mid < k-1)//Ҫ��λ���ڷָ���Ҳ�
        {
            return quickselect(a,mid+1,high,k);
        }
        else//Ҫ��λ���ڷָ�����
        {
            return quickselect(a,low,mid-1,k);
        }
    }
    else//�����ڽ���һ��Ԫ��
    {
        return a[low];
    }
}

int findKthLargest(int *a, int asize, int k)
{
    return quickselect(a,0,asize-1,k);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
