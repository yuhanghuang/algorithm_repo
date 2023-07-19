class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def merge_trees(t1, t2):
    if not t1:
        return t2
    if not t2:
        return t1

    merged = TreeNode(t1.val + t2.val)
    merged.left = merge_trees(t1.left, t2.left)
    merged.right = merge_trees(t1.right, t2.right)

    return merged

if __name__=="__main__":
    # 创建两个二叉树
    t1 = TreeNode(1)
    t1.left = TreeNode(3)
    t1.right = TreeNode(2)
    t1.left.left = TreeNode(5)

    t2 = TreeNode(2)
    t2.left = TreeNode(1)
    t2.right = TreeNode(3)
    t2.left.right = TreeNode(4)
    t2.right.right = TreeNode(7)

    # 合并两个二叉树
    merged_tree = merge_trees(t1, t2)

    # 遍历合并后的二叉树
    def inorder_traversal(node):
        if node:
            inorder_traversal(node.left)
            print(node.val)
            inorder_traversal(node.right)

    inorder_traversal(merged_tree)
