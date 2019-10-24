#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#define  true 1
#define  flase 0
typedef struct
{
  int horiz;
  int vert;
}direction;


direction orient[4] =
{
  {0,-1},    //左,意味着在竖直方向上减一
  {1,0},     //上，意味着在水平方向上加一
  {0,1},     //中
  {-1,0}     //下
};

int a[9][9]=
  {
    1,1,1,1,1,1,1,1,1,
    1,0,1,1,1,1,1,1,1,
    1,0,1,1,0,0,1,1,1,
    1,0,1,0,1,1,1,1,1,
    1,0,0,0,0,0,0,1,1,
    1,1,0,1,1,0,1,1,1,
    1,1,0,1,0,0,0,1,1,
    1,1,1,1,1,1,0,1,1,
    1,1,1,1,1,1,1,1,1
  };

  int start_row = 1;
  int start_col = 1;
  int exit_row = 7;
  int exit_col = 6;

void MazePath()
{
  qSeqStack s = InitStack();          //申请栈
  ElemType e;                        //定义表示在迷宫中走的元素
                                    //对元素进行初始化,初始化为起始点
  e.row = 1;
  e.col = 1;
  e.dir = 0;

  Push(s,e);                       //将起始元素压入栈中

  int row = e.row;                //创建游标元素寻找路径，并赋值为初始点的属性
  int col = e.col;
  int dir = e.dir;
  int find = flase;               //标识元素，用于判断是否找到路径

  while(dir < 3 && !flase)
  {
    int next_row = row + orient[dir].horiz;     //  设置下一个元素的位置的取值
    int next_col = col + orient[dir].vert;

    if(next_row == exit_row && next_col == exit_col)    // 判断下一个是否已经到达终点
    {
      find = true;
      e.row = row;                                     // 把当前元素压入到栈中
      e.col = col;
      e.dir = dir;
      Push(s,e);

      e.row = next_row;                               // 把终点压入栈中
      e.col = next_col;
      e.dir = 0;
      Push(s,e);
    }
    else if(a[next_row] == 0 && a[next_col] == 0)
    {
      e.row = row;          // 把当前元素压到栈中
      e.col = col;
      e.dir = dir;
      Push(s,e);

      row = next_row;      //把下个元素的位置赋值给当前元素
      col = next_col;
      dir = 0;
    }
    else
    dir++;
  }
}

int main()
{
  MazePath();
return 0;
}
