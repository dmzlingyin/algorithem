#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int *base;
    int *top;
}Stack,*pStack;

/*
void convert(int num);
int StackEmpty(pStack s);
int pop(pStack s);
void push(pStack s,int value);
*/
Stack s={0};//�ṹ�������



void InitStack()
{

    s.base = (int *)malloc(100 * sizeof(int));
    if(!s.base)
    {
        printf("�ڴ�����ʧ��!!");
        exit(0);
    }
    s.top = s.base;
    printf("ջ��ʼ���ɹ�!!\n");

}

void push(pStack s,int value)
{
    //�ж�ջ�Ƿ����
    if(s->base - s->top >= 100)
    {
        printf("ջ������������ջʧ��!");
        exit(0);
    }
    *(s->top) = value;
	s->top--;
}

int pop(pStack s)
{
    int tmp = 0;
    //�ж��Ƿ��ǿ�ջ
    if(s->top == s->base)
    {
        printf("��ǰջΪ�գ����ܳ�����");
        exit(0);
    }

    s->top++;
	tmp = *(s->top);
    return tmp;

}
int StackEmpty(pStack s)
{
    if(s->base == s->top )
        return 1;
    return 0;
}
void convert(int num,int scale)
{
    
    while(num)
    {
        push(&s,num % scale);
    
        num /= scale;
    }

}

void main()
{
	int num;//Ҫת����ʮ������
	int scale;//����
    
	InitStack();
    printf("������Ҫת����ʮ������:\n");
    scanf("%d",&num);
	printf("����ת��Ϊ�������أ�\n");
	scanf("%d",&scale);
    convert(num,scale);
	while(!StackEmpty(&s))
	{
		printf("%d",pop(&s));
	}
    printf("\n");
}