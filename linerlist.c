#include<stdlib.h>
#include<stdio.h>

typedef char ElemType
typedef struct Node
{
	ELemType data;
	struct Node  *next;
}Node,*LinkList;

LinkList Init()
{   LinkList L;
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	return L;
}
/*
void CreateFromHead(LinkList L)
{
	Node *s;char c;int flag=1;
	while(flag)
	    c=getchar();
	if(c!='$')
		{
			s=(Node *)malloc(sizeof(Node));
			s->data=c;
			s->next=L->next;
			L->next=s;
		}
    else  flag=0;
}*/
