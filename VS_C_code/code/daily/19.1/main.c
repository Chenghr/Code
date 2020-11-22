#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int low,int high)//һ�˿���
{
    int i=low,j=high;
    int pos = low;//��һ����������׼��
    int temp;

    while (i != j)
    {
        while(i<j && a[j] > a[pos])
        {
            j--;//���������ҳ���һ���Ȼ�׼��С����
        }
        while(i<j && a[i] < a[pos])
        {
            i++;//�������ҳ���һ���Ȼ�׼������
        }

        temp = a[i];//����
        a[i] = a[j];
        a[j] = temp;
    }

    temp = a[i];//������׼����������
    a[i] = a[pos];
    a[pos] = temp;
    return i;//���ػ�׼������
}

void quicksort(int a[],int low,int high)//����
{
    int mid;
    if(low < high)//�������ж��Ԫ��ʱ
    {
        mid = partition(a,low,high);//һ�˻���
        quicksort(a,low,mid);//��벿�ֵݹ�����
        quicksort(a,mid+1,high);//�Ұ벿�ֵݹ�����
    }
}

int main()
{
    int n;
    int a[8] = {0};
    int i,j;
    scanf("%d", &n);//���뼸������
    for(i=0; i<n; i++)//��n��
    {
        for (j=0; j<8; j++)//ÿ�鶼��8������
        {
            scanf("%d", &a[j]);//ѭ��������������
        }

        quicksort(a,0,7);

        for(j=0; j<7; j++)
        {
            printf("%d ",a[j]);
        }
        printf("%d\n",a[7]);//������һ��Ԫ�أ�Ҫ����
    }
    return 0;
}
