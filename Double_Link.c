#include "stdio.h"
#include "stdlib.h"

typedef struct DLNode
{
  struct DLNode *prior; //  在定义内定义结构体时一定要带式struct
  char e;
  struct DLNode *Next;
}LinkList;


LinkList Initial()
{
  LinkList *L;
  L = malloc(sizeof(LinkList)); //  初始化链表的申请
  L->prior = NULL;  //  初始化函数时一定要给指针分配值NULL
  L->Next = NULL;
  return *L;
}

void CreatTail(LinkList *dlK)
{
  char c;
  while((c!=getchar())!='$')
  {
    LinkList *L;   // 先定义变量再申请空间，否则 无变量承受所申请的空间
    L = malloc(sizeof(LinkList));   //  申请空间时sizeof中的名字必须时结构题的下边定义的名字
    L = dlK->Next;
    L->prior = dlK;
    L->e = c;
    L->Next = NULL;
  }
}

void Delete(LinkList *p)
{
  LinkList *q,*h;

  p->prior = q;
  p->Next = h;

  q->Next = h;
  h->prior = q;

  free(p);
}

void DeletePrior(LinkList *p)
{
  LinkList *q;
}
