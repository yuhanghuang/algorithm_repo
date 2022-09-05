/*给定一棵二叉树 root，返回所有重复的子树。
对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
如果两棵树具有相同的结构和相同的结点值，则它们是重复的。*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  }*BiTree;

class Solution {

private:vector<vector<TreeNode*>> vec1;
        int temp=0;

public:
     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
     {
         dfs(root);

     }
    void CreateBiTree(BiTree &T)
{

    int ch;
    cin>>ch;
    if(ch==0) 
	T=NULL;
	else
	{
		T= new TreeNode;
		if(!T) exit(0);
		T->val=ch; 
		CreateBiTree(T->left);  
		CreateBiTree(T->right); 
	}
}

    void PreOrderTraverse(BiTree &T)
{   
	if(T)//当结点不为空的时候执行
	{  
		cout<<T->val;  
		PreOrderTraverse(T->left);//  
		PreOrderTraverse(T->right);  
	}  
	else cout<<"";  
}

    int main() {
        TreeNode* root;
        CreateBiTree(root);
        int n;
        // findDuplicateSubtrees(root);
        PreOrderTraverse(root);
        return 0;

    }
    int dfs(TreeNode* root1){
        TreeNode *p1,*p2;
        if(root1!=nullptr) 
        {
        vec1[temp].push_back(root1);
        dfs(root1->left);
        dfs(root1->right);
        }
        temp++;


        

    }
};
