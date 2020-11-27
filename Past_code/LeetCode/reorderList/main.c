#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

void LinkCreate(struct ListNode *head)//β�巨
{
    struct ListNode *p=head,*q;
    int i=0;
    char c;
    head->next=NULL;
    for(i=0;i<100&&c!='\n';i++){//����ո�����,�س�����
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
1. �ҳ�������м�ڵ㣬�ɲ���˫�ڵ㷨��
2. ��벿����������
3. ǰ�ಿ�ֺͺ�벿�������Ӽ���
*/
struct ListNode * findmid(struct ListNode *head)//�����м��㣬pre->nextΪ�м���
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

 struct ListNode *reverse(struct ListNode *head)//ԭ����������
{

    struct ListNode *pre=NULL,*next;//pre�������ѭ����ǰһ����㣻
    while(head!=NULL)
    {
        next=head->next;//next���浱ǰ������һ�����
        head->next=pre;//��ǰ�ڵ����һ���ڵ�ָ��Ԥ������ѭ���е�ǰһ���ڵ�
        pre=head;//Ԥ��ѭ����ǰһ���ڵ�
        head=next;//headָ���Լ�����һ���ڵ�
    }
    return pre;
}

void merge(struct ListNode *head,struct ListNode *mid)//�ϲ�����������ͷ���
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
