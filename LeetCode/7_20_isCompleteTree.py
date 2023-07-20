from collections import deque
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
    def isCompleteTree(self , root: TreeNode) -> bool:
        # write code here
        result=[]
        if not root:
            result=[]
        # queue=deque()
        # queue.append(root)

        # while(queue):
        #     level_length=len(queue)
        #     level=[]
        #     for i in range(level_length):
        #         node = queue.popleft()
        #         level.append(node.val)

        #         if node.left:
        #             queue.append(node.left)
        #         if node.right:
        #             queue.append(node.right)
        #     result.append(level)
        
        # print(result)
        # print(len(result))
        # for j in range(len(result)-1):
        #     temp=len(result[j])
        #     print(temp)
        #     print("****")
        #     if(temp!=2**j):
        #         return False
        # print(root.val)
        # data=[]

        # 方法二
        queue=[root]
        seen_null=False
        while queue:
            curr=queue.pop(0)
            if curr is None:
                seen_null=True
            else:
                # 下面两行注释一下可以得到层序遍历的结果
                if seen_null:
                    return False
                print(curr.val)
                queue.append(curr.left)
                queue.append(curr.right)
        return True

if __name__=="__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.left.left.right=TreeNode(9)
    root.left.right.left=TreeNode(7)
    sl=Solution()
    print(sl.isCompleteTree(root))  # 输出：True






        # def dfs(root):
        #     if(root==None):
        #         print(0)
        #         data.append(0)
        #         return
        #     print(root.val)
        #     data.append(root.val)
        #     # if(root.left==None and root.right==None):
        #     #     return
        #     dfs(root.left)
        #     dfs(root.right)




        
