#include <iostream>
 
using namespace std;
typedef struct node  
{  
    struct node *lchild;  
    struct node *rchild;  
    // char data;  
    int data;
}BiTreeNode, *BiTree;
//按前序输入二叉树中结点的值
//构造二叉树表表示二叉树T
void CreateBiTree(BiTree &T)
{
	// char ch;
	// cin>>ch;
    int ch;
    cin>>ch;
 
	// if(ch=='#') 
	// 	T=NULL;
    if(ch==0) 
	T=NULL;
	else
	{
		T= new BiTreeNode;
		if(!T) exit(0);
		T->data=ch; 
		CreateBiTree(T->lchild);  
		CreateBiTree(T->rchild); 
	}
}
//前序递归遍历二叉树
void PreOrderTraverse(BiTree &T)
{   
	if(T)//当结点不为空的时候执行
	{  
		cout<<T->data;  
		PreOrderTraverse(T->lchild);//  
		PreOrderTraverse(T->rchild);  
	}  
	else cout<<"";  
}
int main()
{
	BiTree T;
	cout<<"输入对扩展二叉树的前序遍历序列:"<<endl;
 
	CreateBiTree(T);
 
	cout<<"输出前序遍历结果："<<endl;
 
	PreOrderTraverse(T);
	cout<<endl;
 
	return 0;
}