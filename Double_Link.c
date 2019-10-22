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

void CreatTail(LinkList *dlK) //  尾插法进行建表
{
  char c;
  while((c!=getchar())!='$')
  {
    LinkList *L;   // 先定义变量再申请空间，否则 无变量承受所申请的空间
                  //为什么定义变量
    L = malloc(sizeof(LinkList));   //  申请空间时sizeof中的名字必须时结构题的下边定义的名字
     dlK->Next=L ;
    L->prior = dlK;
    L->e = c;
    L->Next = NULL; //  自定义取值为NULL？
  }
}

void Delete(LinkList *p)  //  记录头节点(干啥用的)
{
  LinkList *q,*h;

  p->prior = q;
  p->Next = h;

  q->Next = h;
  h->prior = q;

  free(p);
}

void DeleteNext(LinkList *p)
{
  LinkList *q;
  char c;//保存删除的元素
  q = p->next;

  LinkList *qn; //  没定义，先保存然后再断开连接q->next代替

  qn = q->next;
  p->next = qn;
  qn->prior = p;

  free(q);
}

void Insert(LinkList *p,char c)
{
  LinkList *s,*q;

  s = malloc(sizeof(LinkList));

  s->e = c;
  s = p->next;
  p->next = s;
  s->prior = p;
  s->next = q;
  q->prior = s;

}
