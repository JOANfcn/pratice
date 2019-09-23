#include <stdio.h>
#define true 1
#define flase 0
typedef char ElemType;
typedef struct{
    ElemType elem[20];
    int last;
}List;

List* Initial_List(List* L)
{
  L->last = -1;
  return L;
}

List* Create_number(List* L)
{
  ElemType c;
  int i;
  c=getchar();
  while(c != -1)
  {
    if(L->last != 19 )
    {
      L->elem[i++];
      L->last++;
      c=getchar();
    }
    else
    {printf("此表已满！\n");return;}
  }
  return L;
}

int Judgenull(List* L)
{
  if(L->last == -1)
    return true;
  else
    return flase;
}

int Judgefull(List* L)
{
  if (L->last == 19)
    return true;
 else
    return flase;
}

void Print(List* L)
{
  int i;
  for (i = 0; i<= L->last; i++)
    printf("%d ",L->elem[i]);

}
void Searchbynumber(List *L,int n)
{
  if(Judgenull(L))
    printf("该表为空表！\n" );
  else
    printf("该元素为%d\n",L->elem[n-1] );
}

void Searchbyvolume(List *L,int v)
{
  if(Judgenull(L))
    {printf("该表为空表！\n");return ;}
  if(v<0||v>L->last+1)
    {printf("输入的信息有误\n" );return ;}
  int i;
  for( i=0;i<L->last;i++)
    {
      if(L->elem[i] == v )
      printf("该元素的位置为表中第：%d个元素\n",i+1 );
    }
}

void Delete(List *L,int n)
{
  if(Judgenull(L))
    {printf("该表为空表！\n" );return ;}
  if(n<0||n>L->last+1)
    {printf("输入的位置有误!\n" );}
}

int main() {
  List *L1;
  L1 = Initial_List(L1);
  L1 = Create_number(L1);
  Print(L1);
  return 0;
}
