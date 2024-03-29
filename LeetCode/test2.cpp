/*最大树 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。
给你最大树的根节点 root 和一个整数 val 。
就像 之前的问题 那样，给定的树是利用 Construct(a) 例程从列表 a（root = Construct(a)）递归地构建的：
如果 a 为空，返回 null 。
否则，令 a[i] 作为 a 的最大元素。创建一个值为 a[i] 的根节点 root 。
root 的左子树将被构建为 Construct([a[0], a[1], ..., a[i - 1]]) 。
root 的右子树将被构建为 Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]) 。
返回 root 。
请注意，题目没有直接给出 a ，只是给出一个根节点 root = Construct(a) 。
假设 b 是 a 的副本，并在末尾附加值 val。题目数据保证 b 中的值互不相同。
返回 Construct(b) 。
输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：a = [1,4,2,3], b = [1,4,2,3,5]
*/
/*
 * Definition for a binary tree node.
 * */
// https://leetcode.cn/problems/maximum-binary-tree/ 有最大树的构造方法可以知道一旦遍历的节点比val大的时候就\
一定会放到该节点的右子树上，因此只需要不断遍历右节点即可
#include <malloc.h>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode * p = root;
        struct TreeNode *p1=nullptr;
        p1=(TreeNode *)malloc(sizeof(TreeNode));
        if(root==nullptr){
             return new TreeNode(val);
        }
        else if (val>=(root->val)){
                    // p1->val=val;
                    // p1->left=root;
                    // p1->right=nullptr;
                    // break;
            return new TreeNode(val,root,nullptr);
        }
                // else if(val<p->right->val && val>=p->left->val){
                //     insertIntoMaxTree(p->right,val);
                // }
        else{
            root->right=insertIntoMaxTree(root->right,val);
            return root;
        }               

    }