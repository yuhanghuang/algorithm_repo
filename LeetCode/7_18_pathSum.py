class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> list[list[int]]:
        # ret = list()
        # path = list()
        ret=[]
        path=[]
        
        def dfs(root: TreeNode, target: int):
            if not root:
                return
            path.append(root.val)
            target -= root.val
            if not root.left and not root.right and target == 0:
                # ret.append(path[:])
                ret.extend(path)
            dfs(root.left, target)
            dfs(root.right, target)
            path.pop()
        
        dfs(root, target)
        return ret
if __name__=="__main__":
    root=TreeNode(0)
    root.left=TreeNode(2)
    root.right=TreeNode(8)
    root.left.left=TreeNode(-2)
    sl =Solution()
    print(sl.pathSum(root,0))



# 解法二
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def find_path(root, target):
    if not root:
        return []

    paths = []

    def dfs(node, path, curr_sum):
        curr_sum += node.val
        path.append(node.val)

        # 判断是否为叶子节点且路径和等于目标值
        if not node.left and not node.right and curr_sum == target:
            paths.append(path[:])

        if node.left:
            dfs(node.left, path, curr_sum)
        if node.right:
            dfs(node.right, path, curr_sum)

        # 回溯，移除当前节点
        path.pop()

    dfs(root, [], 0)
    return paths
