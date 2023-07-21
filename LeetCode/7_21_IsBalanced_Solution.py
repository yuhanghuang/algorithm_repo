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
# @return bool布尔型
#
class Solution:
    def IsBalanced_Solution(self , pRoot: TreeNode) -> bool:
        # write code here
        def height(root):
            if root==None:
                return 0
            # print(height(root.left))
            # print(height(root.right))
            return max(height(root.left),height(root.right))+1

        def banlance(root):
            if root==None:
                return True
            left_height=height(root.left)
            right_height=height(root.right)
            if(abs(left_height-right_height)>1):
                return False
            return banlance(root.left) and banlance(root.right)

        if not pRoot:
            return True
        return banlance(pRoot)
    
if __name__=="__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    sl=Solution()
    print(sl.IsBalanced_Solution(root))  # 输出：True



    # 方法二
    '''
    class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def lowest_common_ancestor_bst(root, p, q):
    if not root:
        return None

    if root.value > p.value and root.value > q.value:
        return lowest_common_ancestor_bst(root.left, p, q)
    elif root.value < p.value and root.value < q.value:
        return lowest_common_ancestor_bst(root.right, p, q)
    else:
        return root

# 示例用法:
# 创建一棵搜索二叉树:
#        6
#       / \
#      2   8
#     / \ / \
#    0  4 7  9
#      / \
#     3   5
root = TreeNode(6)
root.left = TreeNode(2)
root.right = TreeNode(8)
root.left.left = TreeNode(0)
root.left.right = TreeNode(4)
root.right.left = TreeNode(7)
root.right.right = TreeNode(9)
root.left.right.left = TreeNode(3)
root.left.right.right = TreeNode(5)

node1 = root.left
node2 = root.right
print(lowest_common_ancestor_bst(root, node1, node2).value)  # 输出：6，因为6是2和8的最近公共祖先
'''