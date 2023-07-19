class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @return bool布尔型
#
class Solution:
    def isValidBST(self , root: TreeNode) -> bool:
        def midtravel(root):
            data=[]
            if root==None:
                return []
            # if(root.val==None and root.right==None):
            #     data.append(root.val)
            data.extend(midtravel(root.left))
            data.append(root.val)
            data.extend(midtravel(root.right))
            return data
        data1=midtravel(root)
        print(data1)
        if(len(data1)==1):
            return True
        for i in range(len(data1)-1):
            if(data1[i]>data1[i+1]):
                return False
        return True

        
        