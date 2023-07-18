class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @return int整型
#
class Solution:
    def maxDepth(self , root: TreeNode) -> int:
        # 解法一
        # if root==None:
        #     return 0
        # left_depth=self.maxDepth(root.left)
        # right_depth=self.maxDepth(root.right)
        # return max(left_depth,right_depth)+1

        # 解法二
        return self.dfstravel(root)

    def dfstravel(self,root:TreeNode) -> int:
        deep=0
        if(root==None):
            return 0
        elif(root.left==None and root.right==None):
            deep+=1
            return deep
        else:
            deepl=1+self.dfstravel(root.left)
            deepr=1+self.dfstravel(root.right)
        return max(deepl,deepr)

