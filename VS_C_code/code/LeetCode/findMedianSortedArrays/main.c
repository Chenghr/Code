#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *a, int asize, int *b, int bsize)
{
    int i,j,imin,imax;
    int maxleft,minright;

    //��ȷ��i�ڽ�С�������в��ң���aΪ��С���Ǹ�����
    if(asize>bsize)
    {
        return findMedianSortedArrays(b,bsize,a,asize);
    }

    //��a������i��������iȷ��j
    imin = 0;
    imax = asize;
    while(imin <= imax)
    {
        //ȷ��i��j
        i = imin + (imax-imin)/2;
        j = (asize+bsize+1)/2 - i;

        //�ж�����
        if(i>imin&&a[i-1]>b[j])//i������i-1>=imin
        {
            imax = i-1;
        }
        else if(i<imax&&a[i]<b[j-1])//i��С����i+1<=imax
        {
            imin = i+1;
        }
        else//�ҵ���������Ҫ��i
        {
            //������߲��ֵ����ֵ
            if(i==0)//�ȴ���һЩ�������
            {
                maxleft = b[j-1];//a[i-1]������
            }
            else if(j==0)
            {
                maxleft = a[i-1];//b[j-1]������
            }
            else
            {
                if(a[i-1]>b[j-1]) maxleft = a[i-1];
                else maxleft = b[j-1];
            }

            //�������ܸ���Ϊ���������ü���������ȥ��ֱ�ӷ���������������
            if( (asize+bsize)%2 == 1) return maxleft;

            //�����ܸ���Ϊż��ʱ����ҪѰ���ұ߲��ֵ���Сֵ
            if(i == asize)
            {
                minright = b[j];//a[i]������
            }
            else if(j == bsize)
            {
                minright = a[i];//b[j]������
            }
            else
            {
                if(a[i]<b[j]) minright = a[i];
                else minright = b[j];
            }

            return (maxleft+minright)/2.0;//����2.0ȷ�����ص���double�ͱ���
        }
    }
    return 0.0;
}

int main()
{
    int a[] = {1,3};
    int b[] = {2};
    double f;
    f = findMedianSortedArrays(a,2,b,1);
    printf("%lf",f);
    return 0;
}
