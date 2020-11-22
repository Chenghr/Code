/*以 [1, 2, 2, 3, 4, 5, 6, 7] 为例
一共有 8 个数，每个数都在 1 和 7 之间。
1 和 7的中位数是 4，
遍历整个数组，统计小于 4 的整数的个数，至多应该为 3 个，
如果超过 3个就说明重复的数存在于区间 [1,4) （注意：左闭右开）中；
否则，重复的数存在于区间 [4,7]（注意：左右都是闭）中
这里小于 4 的整数有 4个（它们是 1, 2, 2, 3），因此砍掉右半区间，连中位数也砍掉。
以此类推，最后区间越来越小，直到变成 1个整数，这个整数就是我们要找的重复的数。
*/
#include <stdio.h>
#include <stdlib.h>
/*
int findDuplicate(int* nums, int numsSize)//二分法的应用
{
    int left=0,right=numsSize-1;//所求的重复数所在区间
    int mid=0;
    int count=0,i=0;
    while(left<right)
    {
        mid=left+(right-left)/2;//奇数取中值，偶数偏左
        count = 0;//计数器置初值
        for(i=0;i<numsSize;i++)//一次遍历，判定下次的区间是左还是右
        {
            if(nums[i]<mid+1)count++;
        }
        if(count<mid+1){//目标在右区间
            left = mid+1;
        }
        else {//目标在左区间
            right = mid;
        }
    }
    return left;//left==right时所指的值即为所求值
}
*/

//快慢指针法，题意本质上就是一个链表中有环，求环的入口
int findDuplicate(int* nums, int numsSize)
{
    int slow=nums[0];
    int fast=nums[slow];
    int find=0;
    while(slow!=fast)//slow和fast在环中相遇
    {
        slow=nums[slow];//slow一次走一步
        fast=nums[nums[fast]];//fast一次走两步
    }
    //fast走了2n步，slow走了n步，相遇，则n为环长的整数倍
    while(find!=slow)//slow和find在环的入口处相遇
    {
        find=nums[find];//slow与find同步前进
        slow=nums[slow];
    }
    /*
    起点到环的距离为m，环长为c
    fast和slow相遇时，slow在环中行进的距离是n-m，其中n%c==0。
    这时我们再让slow前进m步，也就是在环中走了n步了。
    而n%c==0即slow在环里面走的距离是环的周长的整数倍，就回到了环的入口了，而入口就是重复的数字。
    我们不知道起点到入口的长度m，所以find和slow一起走，他们必定会在入口处相遇。
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
    //numsSize = sizeof(num)/sizeof(int);计算数组元素个数的另外一个方法
    dounum = findDuplicate(nums,numsSize);
    printf("%d",dounum);
    return 0;
}
