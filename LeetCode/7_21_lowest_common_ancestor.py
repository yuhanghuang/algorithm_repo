class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# 二叉树寻找最近父节点
# 方法一
class Solution:
    def lowest_common_ancestor(self,root, p, q):
        if not root or root == p or root == q:
            return root
        left_lca = self.lowest_common_ancestor(root.left, p, q)
        right_lca = self.lowest_common_ancestor(root.right, p, q)

        if left_lca and right_lca:
            return root
        elif left_lca:
            return left_lca
        else:
            return right_lca

if __name__=="__main__":
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    print(root)

    node1 = root.left
    node2 = root.right
    sl=Solution()
    print(sl.lowest_common_ancestor(root, node1, node2).val)  # 输出：3，因为3是5和1的最近公共祖先

'''
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param root TreeNode类
# @param o1 int整型
# @param o2 int整型
# @return int整型
#

# 方法二
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: int, q: int) -> int:
        return self.travel(root,p,q).val

    def travel(self,root,p,q):
        if root==None or p==root.val or q==root.val:
            return root

        left_ans=self.travel(root.left,p,q)
        right_ans=self.travel(root.right,p,q)
        if left_ans and right_ans:
            return root
        elif left_ans:
            return left_ans
        else:
            return right_ans

# 方法三
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: int, q: int) -> int:
        
        def travel(root,p,q):
            if root==None or p==root.val or q==root.val:
                return root

            left_ans=travel(root.left,p,q)
            right_ans=travel(root.right,p,q)
            if left_ans and right_ans:
                return root
            elif left_ans:
                return left_ans
            else:
                return right_ans
        return travel(root,p,q).val

'''