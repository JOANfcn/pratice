#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;
typedef struct BiTNode // 定义二叉树结点
{
  ElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBinaryTree(BiTree T) // 用递归的方式创建二叉链表
{
  ElemType e;
  scanf("%c", &e);  // 默认按照前序遍历发输入数


  if( ' ' == e ) // 首先判断输入的c是否为空，若为空则二叉树为空树
  {
    T = NULL;
  }
  else
  {
    T = (BiTNode *)malloc(sizeof(BiTNode));

      T->data = e;
      CreateBinaryTree(T->lchild);
      CreateBinaryTree(T->rchild);
  }
}

void visit(ElemType e,int level)
{
  printf("%c 出现在第 &d 层\n",e,level);
}

void MidOrderTraverse(BiTree T,int level) // 中序遍历遍历二叉链表
{
  if( T )
  {
    visit( T->data,level );
    MidOrderTraverse(T->lchild, level+1);
    MidOrderTraverse(T->rchild, level+1);
  }
}

int main()
{
  int level = 1;
  BiTree T = NULL;
  CreateBinaryTree(T);
  MidOrderTraverse(T,level);
  return 0;
}
