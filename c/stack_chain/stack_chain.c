#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct stacknode
{
    int data;                   //�ڵ�����
    struct stacknode *next;     //�ڵ�ָ��
}StackNode,*pStackNode;

//ջ�ף�ջ�������
typedef struct stack
{
    pStackNode base;     //ջ��
    pStackNode top;      //ջ��
    int stacksize;  //ջ��Ԫ�صĸ���
}Stack,*pStack;

int num = 1314;
int scale = 2;

//��ʼ��һ��stack��ʵ�������0
Stack s = {0};

//ָ��ָ��stackʵ��
pStack pS = &s;


//����ͷָ��
pStackNode StackNodeInit()
{

	pStackNode pHeadNode;
    //ͷ���
    pStackNode HeadNode = (pStackNode)malloc(sizeof(StackNode));
    HeadNode->data = 0;
    HeadNode->next = NULL;
    pHeadNode = HeadNode;//ͷָ��ָ���һ���ڵ�

    return pHeadNode;//����ͷָ��

}

//ÿ��Push������һ��
pStackNode CreatList(pStack s)
{
   
	
        pStackNode pNode = (pStackNode)malloc(sizeof(StackNode));
        pNode->next = s->top;
        pNode->data = 0;
        s->top = pNode;//�����ƶ�ָ��
		return s->top;
 

}


void StackInit(pStackNode p)//����һ������������ΪpStackNode
{
    s.base = p;   //ջ��ָ��ڵ�1
    s.top = s.base;     //ջ��Ҳָ��ڵ�1
    s.stacksize = 0;    //ջ��Ԫ�ظ���Ϊ0
}

void push(pStack s,int value)
{

    s->top->data = value;
    s->top = CreatList(s);

}

//��ջ������ջ��������
int pop(pStack s)
{

	
    int value;
	pStackNode p = s->top;
    if(s->base == s->top)
    {
        printf("ջΪ��,���������!\n");
        exit(0);
    }

    s->top = s->top->next;
    value = s->top->data;
	free(p);
    return value;

}

int StackEmpty(pStack s)
{
    if(s->base == s->top)
        return 1;
    return 0;
}
void convert(pStack s,int num,int scale)
{
    while(num)
    {
        push(s,num % scale);
        num /= scale;
    }
}

void output(pStack s)
{
    while(!StackEmpty(s))
    {
        printf("%d",pop(s));

    }
	printf("\n");
}

void Init()
{
    printf("***************************************************************************\n");
    printf("*                                                                         *\n");
    printf("*                      Welcome to use number convert tool                 *\n");
    printf("*                      This tools was programed by lingyin                *\n");
    printf("*                                 Version 1.0                             *\n");
    printf("*                                                                         *\n");
    printf("*                                                                         *\n");
    printf("***************************************************************************\n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("Please input the NUM that you want to convert:");
    scanf("%d",&num);
    printf("Please input the SCALE that you want to convret:");
    scanf("%d",&scale);


}
void main()
{
    //pΪͷָ��
    pStackNode p = StackNodeInit();

    //ջ�ĳ�ʼ��,��ָ�ӵĳ�ʼ��
    StackInit(p);

    Init();
    convert(pS,num,scale);
    
	//�������
	output(pS);

	

}