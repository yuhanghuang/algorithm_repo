# class TreeNode:

# from numpy import right_shift
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param pRoot TreeNode类
# @return bool布尔型
#
class Solution:
    def isSymmetrical(self, pRoot: TreeNode) -> bool:
        # write code here
        if pRoot == None:
            return True

        def check_system(left, right):
            if left == None and right == None:
                return True
            if left == None or right == None:
                return False
            if left.val != right.val:
                return False
            return check_system(left.left,right.right) and check_system(left.right,right.left)

        # def dfs(left,right):
        #     if(left==None and right==None):
        #         return True
        #     if(left==None or right==None):
        #         return False
        #     elif(left.val!=right.val):
        #         return False
        #     else:
        #         if(left.left and right.right):
        #             dfs(left.left,right.right)
        #         if(left.right and right.left):
        #             dfs(left.right,right.left)
        #         if(left.left and not right.right):
        #             return False
        #         if(left.right and not right.left):
        #             return False
        #         return True
        #         # return True

        # if pRoot==None:
        #     return True
        # if(pRoot.left==None and pRoot.right==None):
        #     return True
        # if(pRoot.left==None or pRoot.right==None):
        #     return False
        return check_system(pRoot.left, pRoot.right)
