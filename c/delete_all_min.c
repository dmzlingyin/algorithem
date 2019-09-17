#include <stdio.h>
#include <stdlib.h>

/*

Date��2019-07-26 22:40
�㷨Ŀ�ģ��ҳ������е���Сֵ����ɾ�����е���Сֵ�ڵ�

�㷨˼�룺�趨һ��preָ�룬����������Сֵ�ڵ��ǰһ���ڵ㡣
*/

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LNode;

//����ĳ�ʼ��������ͷ���
LNode InitList()
{
    LNode L = (LNode)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

//��������
void CreateList(LNode L)
{
    LNode p = L;
    LNode s;
    int i;
    for(i = 0;i < 23;i++)
    {
        s = (LNode)malloc(sizeof(Node));
        s->next = NULL;
        s->data = (rand() % 5) + 2;
        p->next = s;
        p = s;
    }


}

int GetMin(LNode L)
{
    LNode p = L->next;
    LNode pre = L;

    int min = p->data;
    while(p->next != NULL)
    {
        if((p->next->data) < (min))
        {
            pre = p;
            min = p->next->data;
        }

        p = p->next;
    }

    return min;

}
void DeleteMin(LNode L,int min)
{
    LNode p = L->next;
    LNode s;
    while(p != NULL)
    {
        if(p->data == min)
        {
            s = p->next;
            L->next = s;
            free(p);
            p = s;
        }
        else{
            p = p->next;
            L = L->next;
        }
    }
}
int main()
{
    LNode L = InitList();
    LNode t = L;
    int mValue;
    CreateList(L);
    printf("ԭ����:\n");
    while(t->next)
    {
        printf("%d",t->next->data);
        t = t->next;
    }
    printf("\n");
    mValue = GetMin(L);
    printf("��Сֵ��:%d\n",mValue);

    DeleteMin(L,mValue);
    printf("ɾ����Сֵ֮�������:\n");
    while(L->next)
    {
        printf("%d",L->next->data);
        L = L->next;
    }

    return 0;
}
