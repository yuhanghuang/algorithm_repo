class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param pRoot TreeNode类 
# @return TreeNode类
#
class Solution:
    def Mirror(self , pRoot: TreeNode) -> TreeNode:
        # if pRoot==None:
        #     return None
        def dfs(root):
            if not root:
                return None
            left=root.left
            right=root.right
            root.right=left
            root.left=right
            dfs(root.left)
            dfs(root.right)
            return
        dfs(pRoot)
        return pRoot

        # write code here