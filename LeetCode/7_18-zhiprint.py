from collections import deque
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
# @return int整型二维数组
#
class Solution:
    def Print(self , pRoot: TreeNode) -> list[list[int]]:
        data=self.func1(pRoot)
        data1=[]
        j=0
        for i in data:
            if(j%2==0):
                # print(i)
                data1.append(i)
            else:
                temp=[]
                for k in range(len(i)):
                    temp.append(i[len(i)-k-1])
                # print(temp)
                # data1.append(i)
                data1.append(temp)
                # data1.append(i.reverse())
            j+=1
        return data1

    def func1(self,pRoot: TreeNode) -> list[list[int]]:
        if pRoot==None:
            return []
        queue=deque()
        result=[]
        queue.append(pRoot)
        i=0
        # write code here
        while(queue):
            level=[]
            level_length=len(queue)
            for _ in range(level_length):
                node=queue.popleft()
                # node=queue.pop()
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            i+=1    
            result.append(level)
        return result
    
if __name__=="__main__":
    sl=Solution()
    root=TreeNode(8)
    root.left=TreeNode(6)
    root.right=TreeNode(10)
    root.left.left=TreeNode(5)
    root.left.right=TreeNode(7)
    root.right.left=TreeNode(9)
    root.right.right=TreeNode(11)
    # sl.Print(root)
    temps=sl.Print(root)
    for i in temps:
        print(i)