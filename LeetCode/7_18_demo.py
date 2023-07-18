class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @param sum int整型 
# @return bool布尔型
#
class Solution:
    def hasPathSum(self , root: TreeNode, sum: int) -> bool:
        data=self.findpath(root,sum)
        print(data)
        if not data:
            return False
        else:
            return True

    def findpath(self,root:TreeNode,sum:int) ->list[int]: 
        if root==None:
            return []
        paths=[]
        def travel(node,path,curr_sum):
            curr_sum+=node.val
            path.append(node.val)
            if(node.left==None and node.right==None and curr_sum==sum):
                # paths.extend(path)
                paths.append(path)
                # paths.append(path[:])
            if node.left:
                travel(node.left,path,curr_sum)
            if node.right:
                travel(node.right,path,curr_sum)
            path.pop()
        travel(root,[],0)
        return paths
    
if __name__=="__main__":
    sl=Solution()
    root=TreeNode(1)
    root.left=TreeNode(2)
    temps=sl.hasPathSum(root,3)
    if temps:
        print("存在")
    else:
        print("不存在")

        

