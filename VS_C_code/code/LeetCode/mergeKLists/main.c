#include <stdio.h>
#include <stdlib.h>

 struct ListNode
 {
    int val;
    struct ListNode *next;
 };

 struct ListNode* mergetwolist(struct ListNode *l1,struct ListNode *l2)
 {
    struct ListNode *head = NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val<l2->val)
    {
        head = l1;
        head->next = mergetwolist(l1->next,l2);
    }
    else
    {
        head = l2;
        head->next = mergetwolist(l1,l2->next);
    }
    return head;
 }

 struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int mid = listsSize/2;
    int i,j;

    //动态数组的创建
    struct ListNode **left;
    struct ListNode **right;
    left = (struct ListNode*)malloc(mid*sizeof(struct ListNode));
    right = (struct ListNode*)malloc((listsSize-mid)*sizeof(struct ListNode));

    //特殊情况的处理
    if(listsSize==0) return NULL;
    if(listsSize==1) return lists[0];
    if(listsSize==2) return mergetwolist(lists[0],lists[1]);

    //分为左右两部分
    for(i=0;i<mid;i++)
    {
        left[i] = lists[i];
    }
    for(i=mid,j=0;i<listsSize;i++,j++)
    {
        right[j] = lists[i];
    }

    //递归调用即可
    return mergetwolist(mergeKLists(left,mid),mergeKLists(right,listsSize-mid));
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
