from collections import deque
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 求二叉树的右视图
# @param preOrder int整型一维数组 先序遍历
# @param inOrder int整型一维数组 中序遍历
# @return int整型一维数组
#


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class Solution:
    def solve(self, preOrder: list[int], inOrder: list[int]) -> list[int]:
        # write code here
        data1=self.build_tree(preOrder,inOrder)
        self.inorder_traversal(data1)
        data2= self.right_view(data1)
        print(data2)
        data3=data2.pop(0)
        print(data3)
        print(data2)
        return data2
    def build_tree(self, preorder, inorder):
        if not preorder or not inorder:
            return None

        root_val = preorder[0]
        root = TreeNode(root_val)

        root_index_inorder = inorder.index(root_val)

        root.left = self.build_tree(
            preorder[1 : 1 + root_index_inorder], inorder[:root_index_inorder]
        )
        root.right = self.build_tree(
            preorder[1 + root_index_inorder :], inorder[root_index_inorder + 1 :]
        )

        return root
    def right_view(self,root):
        res=[]
        if not root:
            return []
        queue=deque()
        queue.append(root)
        res.append(root.value)
        while(queue):
            level_len=len(queue)
            for i in range(level_len):
                node=queue.popleft()
                if i==level_len-1:
                    res.append(node.value)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return res

    def inorder_traversal(self, root):
        if root:
            self.inorder_traversal(root.left)
            print(root.value, end=" ")
            self.inorder_traversal(root.right)
