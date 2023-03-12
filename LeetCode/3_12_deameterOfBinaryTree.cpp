/**
 * Definition for a binary tree node.
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * */
#include <string>  
#include <iostream>  
#include <vector>
#include<algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    int ans;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int number=1;
        DFS(root);
        return ans-1;

    }
    int DFS(TreeNode* p)
    {
        if(p==nullptr)
            return 0;
        int l=DFS(p->left);
        int r=DFS(p->right);
        ans=max(ans,l+r+1);
        return max(l,r)+1;
    }
};

int main()
{
    Solution sl;
}