#include <stdio.h>
#include <stdlib.h>

int majorityElement(int *a,int asize)
{
    int curnum = a[0];
    int count = 1;
    int i;
    for(i=1;i<asize;i++)
    {
        if(count==0)
        {
            curnum = a[i];
            count = 1;
        }
        else
        {
            if(a[i]==curnum)count++;
            else count--;
        }
    }//һ����������󣬱����curnumΪ�����г��ִ�������Ԫ��
    return curnum;
}


//���η����ֱ������ߺ��ұߵ�������Ȼ��ȫ�ֱ���һ�μ���

int countinrange(int *a,int num,int left,int right)
{
    int count = 0;
    int i = 0;
    for(i=left;i<right+1;i++)
    {
        if(a[i]==num)count++;
    }
    return count;
}

int findmajorityElement(int *a,int left,int right)
{
    int mid = (right-left)/2 +left;
    int lmajor,rmajor;
    int lcount,rcount;

    //����һ��Ԫ��
    if(left==right) return a[left];

    //�ֱ������������
    lmajor = findmajorityElement(a,left,mid);
    rmajor = findmajorityElement(a,mid+1,right);

    //�����������ʱֱ�ӷ���
    if(lmajor==rmajor) return lmajor;

    //������������ʱ��ѡ��Ӯ�ҷ��ظ��ϲ�
    lcount = countinrange(a,lmajor,left,right);
    rcount = countinrange(a,rmajor,left,right);
    return lcount > rcount ? lmajor : rmajor;
}

int majorityElement(int *a,int asize)
{
    return findmajorityElement(a,0,asize-1);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
