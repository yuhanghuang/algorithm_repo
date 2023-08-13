import math

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.color = 'white'
        self.children = []

def isPerfectSquare(n):
    sqrt_n = int(math.sqrt(n))
    return n == sqrt_n * sqrt_n

def getMaxRedNodes(root, graph):
    def dfs(node, parent):
        nonlocal dp
        dp[node][0] = 0
        dp[node][1] = 1 if isPerfectSquare(nodes[node].val) else 0
        
        for child in graph[node]:
            if child != parent:
                dfs(child, node)
                dp[node][0] += max(dp[child][0], dp[child][1])
                dp[node][1] += dp[child][0]
    
    n = len(nodes)
    dp = [[0, 0] for _ in range(n)]
    dfs(root, -1)
    return max(dp[root][0], dp[root][1])

# 示例输入
n = int(input())
weights = list(map(int, input().split()))
nodes = [TreeNode(w) for w in weights]
graph = [[] for _ in range(n)]

for _ in range(n - 1):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

root = 0  # 假设根节点是0，你可以根据实际情况设置根节点
max_red_nodes = getMaxRedNodes(root, graph)
print(max_red_nodes)
