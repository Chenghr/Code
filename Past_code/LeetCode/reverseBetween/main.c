#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* LinkCreate(struct ListNode *head)//尾插法
{
    struct ListNode *p,*q;
    int i=0;
    char c;
    scanf("%d",&head->val);
    c=getchar();
    p = head;
    for(i=1;i<100&&c!='\n';i++)
    {//间隔空格输入,回车结束
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->next = NULL;
        scanf("%d",&q->val);
        c=getchar();
        p->next = q;
        p = q;
    }
    return head;
};

void output(struct ListNode *head)
{
    struct ListNode *p = head;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)//head指向第一个结点
{
    struct ListNode *h,*pre,*tail=NULL,*p;
    int i=0;
    if(m==n)return head;//m等于n时无需操作
    h = (struct ListNode*)malloc(sizeof(struct ListNode));//给head前加上一个头结点
    h->next=head;
    pre = h;
    for(i=1;i<n+1;i++)
    {
        if(i<m)pre=pre->next;
        else if(i==m) tail = pre->next;//pre指向第m-1个结点，tail指向第m个结点
        else//将每个tail后的结点掉到tail前，类似头插法
        {
            p = tail->next;
            tail->next = tail->next->next;
            p->next = pre->next;
            pre->next = p;
        }
    }
    return h->next;
}

int main()
{
    struct ListNode *head;
    int m,n;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    head = LinkCreate(head);
    scanf("%d",&m);
    scanf("%d",&n);
    head = reverseBetween(head,m,n);
    output(head);
    return 0;
}
