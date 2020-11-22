/*�� [1, 2, 2, 3, 4, 5, 6, 7] Ϊ��
һ���� 8 ������ÿ�������� 1 �� 7 ֮�䡣
1 �� 7����λ���� 4��
�����������飬ͳ��С�� 4 �������ĸ���������Ӧ��Ϊ 3 ����
������� 3����˵���ظ��������������� [1,4) ��ע�⣺����ҿ����У�
�����ظ��������������� [4,7]��ע�⣺���Ҷ��Ǳգ���
����С�� 4 �������� 4���������� 1, 2, 2, 3������˿����Ұ����䣬����λ��Ҳ������
�Դ����ƣ��������Խ��ԽС��ֱ����� 1�����������������������Ҫ�ҵ��ظ�������
*/
#include <stdio.h>
#include <stdlib.h>
/*
int findDuplicate(int* nums, int numsSize)//���ַ���Ӧ��
{
    int left=0,right=numsSize-1;//������ظ�����������
    int mid=0;
    int count=0,i=0;
    while(left<right)
    {
        mid=left+(right-left)/2;//����ȡ��ֵ��ż��ƫ��
        count = 0;//�������ó�ֵ
        for(i=0;i<numsSize;i++)//һ�α������ж��´ε�������������
        {
            if(nums[i]<mid+1)count++;
        }
        if(count<mid+1){//Ŀ����������
            left = mid+1;
        }
        else {//Ŀ����������
            right = mid;
        }
    }
    return left;//left==rightʱ��ָ��ֵ��Ϊ����ֵ
}
*/

//����ָ�뷨�����Ȿ���Ͼ���һ���������л����󻷵����
int findDuplicate(int* nums, int numsSize)
{
    int slow=nums[0];
    int fast=nums[slow];
    int find=0;
    while(slow!=fast)//slow��fast�ڻ�������
    {
        slow=nums[slow];//slowһ����һ��
        fast=nums[nums[fast]];//fastһ��������
    }
    //fast����2n����slow����n������������nΪ������������
    while(find!=slow)//slow��find�ڻ�����ڴ�����
    {
        find=nums[find];//slow��findͬ��ǰ��
        slow=nums[slow];
    }
    /*
    ��㵽���ľ���Ϊm������Ϊc
    fast��slow����ʱ��slow�ڻ����н��ľ�����n-m������n%c==0��
    ��ʱ��������slowǰ��m����Ҳ�����ڻ�������n���ˡ�
    ��n%c==0��slow�ڻ������ߵľ����ǻ����ܳ������������ͻص��˻�������ˣ�����ھ����ظ������֡�
    ���ǲ�֪����㵽��ڵĳ���m������find��slowһ���ߣ����Ǳض�������ڴ�������
    */
    return find;
}

int main()
{
    int nums[100];
    int numsSize=0,i=0;
    int dounum=0;
    char s;
    for(i=0;i<100&&s!='\n';i++)
    {
        scanf("%d",&nums[i]);
        s=getchar();
        numsSize++;
    }
    //numsSize = sizeof(num)/sizeof(int);��������Ԫ�ظ���������һ������
    dounum = findDuplicate(nums,numsSize);
    printf("%d",dounum);
    return 0;
}
