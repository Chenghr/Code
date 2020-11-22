#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* LinkCreate(struct ListNode *head)//β�巨
{
    struct ListNode *p,*q;
    int i=0;
    char c;
    scanf("%d",&head->val);
    c=getchar();
    p = head;
    for(i=1;i<100&&c!='\n';i++)
    {//����ո�����,�س�����
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

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)//headָ���һ�����
{
    struct ListNode *h,*pre,*tail=NULL,*p;
    int i=0;
    if(m==n)return head;//m����nʱ�������
    h = (struct ListNode*)malloc(sizeof(struct ListNode));//��headǰ����һ��ͷ���
    h->next=head;
    pre = h;
    for(i=1;i<n+1;i++)
    {
        if(i<m)pre=pre->next;
        else if(i==m) tail = pre->next;//preָ���m-1����㣬tailָ���m�����
        else//��ÿ��tail��Ľ�����tailǰ������ͷ�巨
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
