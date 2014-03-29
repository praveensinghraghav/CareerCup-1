/*******************
��Ŀ������
������ջʵ��һ������
Data:2014-03-29
********************/

/**************************************************************************************************************
����Ϊ����ջ���㷨����ջΪ��̬ջ��
�ڸ�ջ�У�pTopָ��Ľڵ��д�Ÿ�ջ��ջ������
pBottomָ��Ľڵ����һ���ڵ��Ÿ�ջ��ջ�����ݣ�pBottomָ��Ľڵ��в������Ч���ݣ�
��������Ŀ����Ϊ���ڽ�����ջ�ͳ�ջʱ�����ջ�Ĳ��������ÿ����������
**************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

PSTACK create_stack();
void push_stack(PSTACK,int);
void traverse_stack(PSTACK);
bool pop_stack(PSTACK,int *);
bool is_empty(PSTACK);
void clear_stack(PSTACK);
void enter_Queue(PSTACK,int);
bool delete_Queue(PSTACK,PSTACK,int *);

int main()
{	
	int data_pop;
	//����һ���յ�ջ��pSָ��ָ���ջ
	PSTACK pS1 = create_stack();
	PSTACK pS2 = create_stack();

	enter_Queue(pS1,1);
	enter_Queue(pS1,2);
	enter_Queue(pS1,3);

	delete_Queue(pS1,pS2,&data_pop);
	printf("The pop data:%d\n",data_pop);
	delete_Queue(pS1,pS2,&data_pop);
	printf("The pop data:%d\n",data_pop);

	enter_Queue(pS1,4);
	enter_Queue(pS1,5);

	delete_Queue(pS1,pS2,&data_pop);
	printf("The pop data:%d\n",data_pop);

	enter_Queue(pS1,6);

	delete_Queue(pS1,pS2,&data_pop);
	printf("The pop data:%d\n",data_pop);
	delete_Queue(pS1,pS2,&data_pop);
	printf("The pop data:%d\n",data_pop);
	delete_Queue(pS1,pS2,&data_pop);
	printf("The pop data:%d\n",data_pop);

	return 0;
}

/*
����һ����ջ,������ָ���ջ��ָ��
*/
PSTACK create_stack()
{
	PSTACK pS = (PSTACK)malloc(sizeof(STACK));
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL==pS || NULL==pS->pTop)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pS->pBottom = pS->pTop;
	   pS->pBottom->pNext = NULL;
	}
	
	return pS;
}

/*
�жϸ�ջ�Ƿ�Ϊ��
*/
bool is_empty(PSTACK pS)
{
	if(pS->pTop == pS->pBottom)
	   return true;
    else
	   return false;
}

/*
��pSָ��ָ���ջ��ѹ������val
*/
void push_stack(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pNew->data = val;
	   pNew->pNext = pS->pTop;
	   pS->pTop = pNew;
	}	
	return ;
}

/*
��ջ���Ƴ����ݣ������Ƴ������ݱ�����pDataָ����ָ���λ��
*/
bool pop_stack(PSTACK pS,int *pData)
{
	if(is_empty(pS))
	   return false;
	else
	{
	   PNODE p = pS->pTop;
	   *pData = p->data;
	   pS->pTop = p->pNext;
	   free(p);
	   p = NULL;
	   return true;
	}
}

/*
����ջ������ջ����ջ�����ջ�е�����
*/
void traverse_stack(PSTACK pS)
{
	PNODE pCurrent = pS->pTop; 
	printf("Now datas int the stack are:\n");
	while(pCurrent != pS->pBottom)
       {
	   printf("%d ",pCurrent->data);
	   pCurrent = pCurrent->pNext;
	}
	printf("\n");
	return ;
}

/*
���ջ�������仹ԭΪ��ջ
*/
void clear_stack(PSTACK pS)
{
	if(is_empty(pS))
	   return ;
	else
	{
	   PNODE p = pS->pTop;
	   PNODE r = NULL;
	   while(p != pS->pBottom)
	   {
			r = p->pNext;
			free(p);
			p = r;
	   }
	   pS->pTop = pS->pBottom;
   	}
}

/*
������ջģ�����
*/
void enter_Queue(PSTACK pS1,int val)
{
	push_stack(pS1,val);
}

/*
������ջģ�����
*/
bool delete_Queue(PSTACK pS1,PSTACK pS2,int *pData)
{
	if(is_empty(pS1) && is_empty(pS2))
		return false;
	if(!is_empty(pS2))
		pop_stack(pS2,pData);
	else if(!is_empty(pS1))
	{
		while(!is_empty(pS1))
		{
			int pS1_popData;
			pop_stack(pS1,&pS1_popData);
			push_stack(pS2,pS1_popData);
		}
		pop_stack(pS2,pData);
	}
	return true;
}