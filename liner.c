#include <stdio.h>
#include <stdlib.h>
#define true 1  //  宏定义true为1
#define flase 0 //  宏定义flase为0
typedef char ElemType;
typedef struct{
    ElemType elem[20];    //  顺序表中的元素的个数
    int last;           //  用来存放顺序表中最后一个元素的下角标
}List;                //定义一个List的结构体为顺序表

List *InitialList() // 初始化顺序表
{
  List *L = malloc(sizeof(List)); //  在初始化定义的时候一定要先申请命名空间
  L->last = -1;

  return L; // 直接在指针上进行修改
}

void Createnumber(List *L)  //  为顺序表输入取值
{
  ElemType c;
  int i = 0 ; //  应定义函数的游标变量为0由此只想顺序表中的位置进行赋值

  while((c = getchar()) != '$'&&L->last != 19)
  {

    L->elem[i++] = c;
    L->last++;

    if(L->last>19)
    {
      printf("full!\n" );
      return ;
    }
  }

}

int Judgenull(List *L)  //  判空函数
{
  if(L->last == -1 )
    return true;
  else
    return flase;
}

int Judgefull(List *L)  // 判满函数
{
  if (L->last == 19)
    return true;
 else
    return flase;
}

void Print(List *L) //  输出顺序表中的取值
{
  int i;

  for (i = 0; i<= L->last; i++)
    printf("%c ",L->elem[i]);

}

void SearchbyPosition(List *L,int i)  //  按位置查找顺序表中的取值,该位置指的是表中的第几个元素
{
  if(Judgenull(L))
    {
      printf("plenty!\n" );
      return ;
    }

  if(i<=0||i>L->last+1)
    {
      printf("wrong message\n" );
      return ;
    }

    printf("\nthe volume of element is %c\n",L->elem[i-1] );
}

void SearchbyValue(List *L, ElemType e)  //  按值查找顺序表中的元素
{
  if(Judgenull(L))
    {
      printf("plenty form!\n");
      return ;
    }

  int i;
  int f=1;

  for( i=0;i<=L->last;i++)
    {
      if(L->elem[i] == e )
      {
        printf("the position of element is %d\n",i+1 );
        f=0;
      }
    }

    if(f == 1)
      printf("no elemt!");

}

void Delete(List *L,int i) // 删除函数形参为顺序表的首地址和被删除元素的位置
{
    if(Judgenull(L))
  {
    printf("Empty!\n" );
    return ;
  }

  if(i<=0||i>L->last+1)
    {
      printf("wrong message\n" );
      return ;
    }

  int j;
  j = i;

  while(j<L->last)
  {
    L->elem[j] = L->elem[j+1];
    j++;
  }

  L->last--;

}

void DeletebyValue(List *L,ElemType e) // 删除函数，形参为顺序表的首地址和被删除元素的取值
{
  if(Judgenull(L))
  {
    printf("Empty!\n" );
    return ;
  }

  int i;
  int f=1;  //  判断该元素是否找到的标记变量

  for( i=0;i<=L->last;i++) //  首先要找到该元素的位置
    {
      if(L->elem[i] == e )
      {
        Delete(L,i);
        f=0;
      }
    }

    if(f == 1)  //  如果没有找到元素的位置则返回报错信息
      printf("no elemt!\n");

}

void Insert(List *L,int i,ElemType e) // 插入函数形参为顺序表的首地址和需要插入元素的位置和需要插入元素的取值
{
  if(Judgefull(L))  //  如果该函数已经满了，则无法插入
  {
    printf("Full!\nCan't insert anything!\n");
    return ;
  }

  if(i<=0||i>L->last+1)
  {
    printf("wrong message\n" );
    return ;
  }

  int j;
  j = L->last;

  while(j>=i-1)
  {
    L->elem[j+1] = L->elem[j];
    j--;
  }

  L->elem[j-1] = e;
  L->last++;

}

void Modify(List *L,int i,ElemType e)  //  修改函数，形参为顺序表的首地址，所需要修改元素的位置和修改后该元素的值
{
    if(Judgenull(L))
    {
      printf("plenty!\n" );
      return ;
    }

  if(i<=0||i>L->last+1)
    {
      printf("wrong message\n" );
      return ;
    }

    L->elem[i-1] = e;
}

void ModifybyValue(List *L,ElemType e,ElemType ec)  //  修改函数形参为顺序表的首地址和所要修改的元素的值和修改后该元素的值
{
  if(Judgenull(L))
  {
    printf("plenty form!\n");
    return ;
  }

  int i;
  int f=1;

  for( i=0;i<L->last;i++)
    {
      if(L->elem[i] == e )
      {
        L->elem[i] = ec;
        f=0;
      }
    }

    if(f == 1)
      printf("no elemt!");
}

void Reverse(List *L)
{
  if(Judgenull(L))
  {
    printf("Empty!\n");
    return ;
  }

  int i,j,t;
  i = 0;
  j = L->last;

  while(i<j)
  {
    t = L->elem[i];
    L->elem[i] = L->elem[j];
    L->elem[j] = t;
    i++;
    j--;
  }

}

void BubbleSort(List *L)
{
  if(Judgenull(L))
  {
    printf("Empty\n");
    return ;
  }

  int i,j;
  ElemType t;

  for(i=0;i<=L->last;i++)
    for(j=0;j<=L->last-1-i;j++)
      if(L->elem[j]>L->elem[j+1])
      {
        t = L->elem[j];
        L->elem[j] = L->elem[j+1];
        L->elem[j+1] = t;
      }
}



int main() {
  List *L1;
  L1 = InitialList();
  Createnumber(L1);
  Print(L1);
  printf("\n" );
  BubbleSort(L1);
  Print(L1);

  return 0;
}
