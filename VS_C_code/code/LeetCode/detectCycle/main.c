#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    struct ListNode *find=head;
    int flag=0;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast&&slow==fast)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        while(slow!=find)
        {
            find=find->next;
            slow=slow->next;
        }
        return find;
    }
    return NULL;
}

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
int main()
{
    struct ListNode *head,*p;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    LinkCreate(head);
    p=detectCycle(head);
    if(p==NULL)printf("0\n");
    else printf("%d",p->val);
    return 0;
}
