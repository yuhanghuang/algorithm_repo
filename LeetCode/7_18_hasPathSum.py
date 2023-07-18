class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @param sum int整型 
# @return bool布尔型
#
class Solution:
    def hasPathSum(self , root: TreeNode, sum: int) -> bool:
        data=self.dfstravel(root)
        print(data)
        if root is not None and sum==root.val:
            if root.left==None and root.right==None:
                return True
            else:
                return False
        if sum in data:
            return True
        else:
            return False
    
    def dfstravel(self, root:TreeNode)->list[int]:
        # write code here
        result=[]
        if root==None:
            return []
        if(root.left==None and root.right==None):
                result.append(root.val)
                return result
        end=[]
        temp=self.dfstravel(root.left)
        for i in range(len(temp)):
            # end.append(i)
            temp[i]+=root.val
            # i+=root.val
        data1=temp

        end=[]
        temp=self.dfstravel(root.right)
        for i in temp:
            end.append(i)
        data2=root.val+sum(end)
        result.append(data1)
        result.append(data2)
        return result
# {0,2,8,-2},0

if __name__=="__main__":
    root=TreeNode(0)
    root.left=TreeNode(2)
    root.right=TreeNode(8)
    root.left.left=TreeNode(-2)
    sl =Solution()
    sl.hasPathSum(root,0)