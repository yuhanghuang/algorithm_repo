# 定义一个节点类，包含元素值，左子节点和右子节点
class Node:
	def __init__(self, elem):
		self.elem = elem
		self.left = None
		self.right = None

# 定义一个树类，包含一个根节点
class Tree:
	def __init__(self, root=None):
		

# 添加节点的方法，使用广度优先遍历的方式
def add(self, elem):
	node = Node(elem) # 创建一个新节点
	if not self.root: # 如果根节点为空，直接将新节点作为根节点
		self.root = node
		return
	queue = [self.root] # 使用一个队列来存储待处理的节点
	while queue: # 循环直到队列为空
		cur = queue.pop(0) # 弹出队首的节点
		if not cur.left: # 如果左子节点为空，将新节点作为左子节点
			cur.left = node
			return
		elif not cur.right: # 如果右子节点为空，将新节点作为右子节点
			cur.right = node
			return
		else: # 如果左右子节点都不为空，将它们加入队列继续处理
		queue.append(cur.left)
		queue.append(cur.right)

# 测试代码
tree = Tree() # 创建一个空树
tree.add(1) # 添加根节点 1
tree.add(2) # 添加左子节点 2
tree.add(3) # 添加右子节点 3
tree.add(4) # 添加左子节点的左子节点 4
tree.add(5) # 添加左子节点的右子节点 5

# 此时树的结构如下：
# 1
# / \
# 2 3
# / \
# 4 5

```
