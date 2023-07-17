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
# @return int整型一维数组
#
class Solution:
    def inorderTraversal(self , root: TreeNode) -> List[int]:
        # write code here
        data=[]
        if root==None:
            return []
        if(root.val==None and root.right==None):
            data.append(root.val)
        data.extend(self.inorderTraversal(root.left))
        data.append(root.val)
        data.extend(self.inorderTraversal(root.right))
        return data
    def postorderTraversal(self , root: TreeNode) -> List[int]:
        if root==None:
            return []
        data=[]
        if root.left==None and root.right==None:
            print(root.val)
            data.append(root.val)
        data.extend(self.postorderTraversal(root.left))
        data.extend(self.postorderTraversal(root.right))
        # data.append(root.val)
        return data
