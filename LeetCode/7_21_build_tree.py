class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
class Solution:
    def build_tree(self,preorder, inorder):
        if not preorder or not inorder:
            return None

        root_val = preorder[0]
        root = TreeNode(root_val)

        root_index_inorder = inorder.index(root_val)

        root.left = self.build_tree(preorder[1:1 + root_index_inorder], inorder[:root_index_inorder])
        root.right = self.build_tree(preorder[1 + root_index_inorder:], inorder[root_index_inorder + 1:])

        return root

    def inorder_traversal(self,root):
        if root:
            self.inorder_traversal(root.left)
            print(root.value, end=' ')
            self.inorder_traversal(root.right)

if __name__=="__main__":

    # 示例用法:
    preorder_list = [3, 9, 20, 15, 7]
    inorder_list = [9, 3, 15, 20, 7]
    sl=Solution()
    root = sl.build_tree(preorder_list, inorder_list)
    sl.inorder_traversal(root)  # 输出：9 3 15 20 7
