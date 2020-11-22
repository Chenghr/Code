#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

void LinkCreate(struct ListNode *head)//尾插法
{
    struct ListNode *p=head,*q;
    int i=0;
    char c;
    head->next=NULL;
    for(i=0;i<100&&c!='\n';i++){//间隔空格输入,回车结束
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&q->val);
        c=getchar();
        p->next=q;
        q->next=NULL;
        p=q;
    }
};

void output(struct ListNode *head)
{
    struct ListNode *p = head->next;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

/*
1. 找出链表的中间节点，可采用双节点法；
2. 后半部分链表逆序
3. 前班部分和后半部交叉连接即可
*/
struct ListNode * findmid(struct ListNode *head)//查找中间结点，pre->next为中间结点
{
    struct ListNode *fast,*slow,*mid;
    fast=head->next;
    slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    mid=slow->next;
    slow->next=NULL;
    return mid;
};

 struct ListNode *reverse(struct ListNode *head)//原地逆置链表
{

    struct ListNode *pre=NULL,*next;//pre保存遍历循环中前一个结点；
    while(head!=NULL)
    {
        next=head->next;//next保存当前结点的下一个结点
        head->next=pre;//当前节点的下一个节点指向预留遍历循环中的前一个节点
        pre=head;//预留循环的前一个节点
        head=next;//head指向自己的下一个节点
    }
    return pre;
}

void merge(struct ListNode *head,struct ListNode *mid)//合并两个链表，带头结点
{
    struct ListNode *next;
    while(mid!=NULL)
    {
        next=mid->next;
        mid->next=head->next;
        head->next=mid;
        mid=next;
        head=mid->next->next;
    }
}

void reorderList(struct ListNode* head)
{
    struct ListNode *p,*q,*mid;
    mid = findmid(head);
    mid = reverse(mid->next);
    merge(head->next,mid);
}

int main()
{
    struct ListNode *head;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    LinkCreate(head);
    output(head);
    reorderList(head);
    output(head);
    return 0;
}
