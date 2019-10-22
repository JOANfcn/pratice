#include"stdio.h"
#include "stdlib.h"
#define StackSize 20
#define Increasement 10

typedef struct                         //定义迷宫中的元素的位置
{
  int row;
  int col;
}element;

typedef element ElemType;

typedef struct                          //定义顺序栈额结构体
{
  ElemType *base;                       //指向栈底
  ElemType *top;                        //指向栈顶
  int size;                             //表示栈的容量
}SeqStack;


SeqStack *Initial();                    // 初始化一个栈
int StackLen(SeqStack *s);              // 当前栈的长度
void Push(SeqStack *s,ElemType e);      //压栈操作
void Pop(SeqStack *s,ElemType *e);      //出栈操作，注意是传递地址
void DestoryStack(SeqStack *s);         //摧毁栈
ElemType Get(SeqStack *s);              //取出栈顶的值

SeqStack *Initial()
{
  SeqStack *s;
  s->base = malloc( StackSize * sizeof(ElemType) );

  if(!s->base)                         //判断是否申请失败
  {
    printf("Fail\n");
    exit(0);
  }

  s->top = s->base;                  //表示空栈
  s->size = StackSize;               //给StackSize赋值为当前栈的容量
  return s;                          //返回所创建的栈的地址
}

int StackLen(SeqStack *s)
{
  return(s->top-s->base);           //求栈的当前的容量
}

void Push(SeqStack *s,ElemType e)
{
  if(s->top-s->base>=s->size)
  {
    s->base =( ElemType * )  realloc( s->base,(StackSize+Increasement) * sizeof( ElemType ) );

    if(!s->base)               //判断是否成功申请空间
    {
      printf("Fail\n");
      exit(0);
    }
    s->top = s->base + s->size;   //设置栈顶
    s->size = s->size + Increasement; // 重新设置栈的容量
  }

  *( s->top ) = e;                //为栈顶赋值
  s->top++;                       //栈顶推进
}

void Pop(SeqStack *s,ElemType *e)
{
  if( s->base == s->top )       //判断此栈是否为空
  {
    printf("Empty！\n");
    return ;
  }

  *e = *(s->top--);           //将删除的元素传递出，先将s->top--之后再将值赋值给e
}

void DestoryStack(SeqStack *s)
{
  int i,len;
  len = s->size;

  for( i=0 ; i<len ; i++ )          //历遍每个元素，依次释放
  {
    free(s->base);
    s->base++;
  }

  s->base = s->top = NULL;        //对s->base,s->top赋予空值
  s->size = 0;                    //长度为0
}

ElemType Get(SeqStack *s)
{
  if ( s->base == s->top )
  {
    printf("Empty!\n");
    exit(0);
  }

  return *(s->top--);
}
