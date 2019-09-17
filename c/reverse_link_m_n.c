/*
Date:20-9-07-19
Author:lingyin

��Ŀ:��ת������m��n
*/

#include<stdio.h>
#include<malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* createList()
{
    int i;
    struct ListNode* L = NULL;
    struct ListNode* s;
    struct ListNode* La;

    //��Ԫ���
    L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->val = 1;
    La = L;

    //β�巨��������
    for(i = 2;i < 6;i++)
    {
        s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val = i;
        s->next = NULL;
        L->next = s;
        L = s;

    }
    return La;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){


    struct ListNode *left,*right,*tmp,*p;
    struct ListNode *re = head;

    int i,j;
    if(m > n)
        return 0;
    if(m == 1)
    {
        left = (struct ListNode*)malloc(sizeof(struct ListNode));
        left->next = head;
    }
    else
    {
        for(i = 1;i < m-1;i++)
            head = head->next;
        left = head;//����mǰһ��ָ��
    }

    p = left->next;

    if(m == 1)
        for(j = m;j < n;j++)
            head = head->next;

    else
        for(j = m;j <= n;j++)
            head = head->next;

    right = head->next;
    left->next = right;

    while(p != right)
    {
        tmp = p->next;
        p->next = left->next;
        left->next = p;
        p = tmp;

    }
    if(m == 1)
        return left->next;

    return re;

}
int main()
{


    struct ListNode *L = createList();
    struct ListNode *T = reverseBetween(L,1,4);
    while(T)
    {

        printf("%d\n",T->val);
        T = T->next;
    }
    return 0;
}
