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
class Solution {
    // vector<int> vec1;
private:
    int res;

public:
    int longestUnivaluePath(TreeNode* root) {
        TreeNode * p =(TreeNode *)malloc(sizeof(TreeNode));
        vector<int> vec1;
        res=0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root)
    {
        if(root==nullptr) return 0;
        int left=dfs(root->left),right=dfs(root->right);
        int left1=0;
        int right1=0;
        if(root->left && root->val==root->left->val){
            left1=left+1;
        }
        if(root->right && root->right->val==root->right->val){
            right1=right+1;
        }
        res = max(res,left1+right1);
        return max(left1,right1);

    }
};