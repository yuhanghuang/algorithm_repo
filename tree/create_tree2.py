from _testcapi import INT_MIN
# 7
# 0 1 8
# 1 -1 -2
# 2 1 9
# 4 0 -2
# 5 4 3
# 3 0 -3
# 6 2 -3
n_line = int(input())
data=[]
for i in range(n_line):
    data.append(list(map(int,input().split())))

class Node:
    def __init__(self,id,val):
        self.id = id
        self.next = set()
        self.val = val


nodes=dict()

for l in data:
    nodes[l[0]] = Node(l[0],l[2])

root_nodes=[]
for l in data:
    node = nodes[l[0]]
    if l[1]==-1:
        root_nodes.append(node)
    else:
        parent = nodes[l[1]]
        parent.next.add(node)

res=INT_MIN
def dfs(root,grade=0):
    global res
    grade = 0 if grade+root.val <0 else grade+root.val
    res = max(grade, res)
    for node in root.next:
        dfs(node,grade)

for node in root_nodes:
    dfs(node)
print(res)