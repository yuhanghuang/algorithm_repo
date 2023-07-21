from sre_compile import JUMP
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
# @param p int整型 
# @param q int整型 
# @return int整型
#
class Solution:
    def lowestCommonAncestor(self , root: TreeNode, p: int, q: int) -> int:
        if not root:
            return None
        elif(root.val>p and root.val>q):
            return self.lowestCommonAncestor(root.left,p,q)
        elif(root.val<p and root.val<q):
            return self.lowestCommonAncestor(root.right,p,q)
        else:
            return root.val
        
        # 方法二
        # # write code here
        # data=[]
        # def preorder(root):
        #     if root==None:
        #         return []
        #     temp=[]
        #     temp.append(root.val)
        #     temp.extend(preorder(root.left))
        #     temp.extend(preorder(root.right))
        #     return temp
        # if root==None:
        #     return 0
        # datas=preorder(root)
        # # print(datas)
        # def dfs(root):
        #     if not root:
        #         return []
        #     data.append(preorder(root))
        #     data.append(dfs(root.left))
        #     data.append(dfs(root.right))

        # dfs(root)
        # result=[]
        # for i in data:
        #     if i:
        #         result.append(i)
        # print(result)
        # for index in range(len(result)):
        #     if(p in result[len(result)-1-index] and q in result[len(result)-1-index]):
        #         print(result[len(result)-1-index])
        #         ended=index
        #         break
        # # print(result[len(result)-1-ended])
        # tt=result[len(result)-1-ended]
        # return tt[0]