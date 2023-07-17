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
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 先序遍历
    def preorder_traversal_recursive(self,root):
        if root is None:
            return []
        result = []
        result.append(root.val)
        result.extend(self.preorder_traversal_recursive(root.left))
        result.extend(self.preorder_traversal_recursive(root.right))
        return result
    
    # 中序遍历
    def inorderTraversal(self , root) -> list[int]:
    # write code here
        data=[]
        if root==None:
            return []
        if(root.val==None and root.right==None):
            data.append(root.val)
            return data
        data.extend(self.inorderTraversal(root.left))
        data.append(root.val)
        data.extend(self.inorderTraversal(root.right))
        return data
    
    # 后序遍历
    def postorderTraversal(self , root ) -> list[int]:
        if root==None:
            return []
        data=[]
        if root.left==None and root.right==None:
            # print(root.val)
            data.append(root.val)
            return data
        # else:
        data.extend(self.postorderTraversal(root.left))
        data.extend(self.postorderTraversal(root.right))
        data.append(root.val)
        return data
        # write code here
if __name__=="__main__":
    # 创建二叉树
    # root = TreeNode(1)
    # root.left = TreeNode(2)
    # root.right = TreeNode(3)
    # root.left.left = TreeNode(4)
    # root.left.right = TreeNode(5)
    root=TreeNode(1)
    root.right=TreeNode(2)
    root.right.left=TreeNode(3)
    sl=TreeNode()
    # 先序遍历二叉树
    # result = sl.preorder_traversal_recursive(root)
    # result=sl.postorderTraversal(root)
    print(sl.preorder_traversal_recursive(root))
    print(sl.inorderTraversal(root))
    print(sl.postorderTraversal(root))
    # print(result)
