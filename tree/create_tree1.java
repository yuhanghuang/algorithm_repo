//定义二叉树节点类
class TreeNode {
int data; //数据域
TreeNode left; //左子节点引用
TreeNode right; //右子节点引用

//构造方法
public TreeNode(int data) {
	this.data = data;
	this.left = null;
	this.right = null;
}
}

//定义二叉树类
class BinaryTree {
TreeNode root; //根节点引用

//构造方法
public BinaryTree() {
this.root = null;
	}

//插入方法，递归地在合适的位置插入新节点
public void insert(int data) {
	this.root = insert(this.root, data);
}

private TreeNode insert(TreeNode node, int data) {
	if (node == null) 
	{ //如果当前节点为空，创建新节点并返回
		return new TreeNode(data);
	}
	if (data < node.data) 
	{ //如果数据小于当前节点，递归地在左子树中插入
		node.left = insert(node.left, data);
	} 
	else if (data > node.data) 
	{ //如果数据大于当前节点，递归地在右子树中插入
		node.right = insert(node.right, data);
	} 
	else 
	{ //如果数据等于当前节点，不做任何操作
	//可以根据需要抛出异常或者允许重复值
	}
return node; //返回当前节点
}

//删除方法，递归地删除指定的节点，并保持二叉搜索树的性质
public void delete(int data) {
	this.root = delete(this.root, data);
}

private TreeNode delete(TreeNode node, int data) {
	if (node == null) { //如果当前节点为空，返回null
		return null;
	}
	if (data < node.data) { //如果数据小于当前节点，递归地在左子树中删除
		node.left = delete(node.left, data);
	} 
	else if (data > node.data) { //如果数据大于当前节点，递归地在右子树中删除
		node.right = delete(node.right, data);
	} 
	else 
	{ //如果数据等于当前节点，分三种情况处理
		if (node.left == null && node.right == null) { //如果当前节点是叶子节点，直接删除
		return null;
	} 
	else if (node.left == null) { //如果当前节点只有右子树，用右子树替换当前节点
		return node.right;
	} 
	else if (node.right == null) { //如果当前节点只有左子树，用左子树替换当前节点
		return node.left;
	} 
	else 
	{ //如果当前节点有两个子树，用右子树中的最小值替换当前节点，并删除右子树中的最小值
		TreeNode min = findMin(node.right); //找到右子树中的最小值
		node.data = min.data; //用最小值替换当前节点的数据域
		node.right = delete(node.right, min.data); //递归地删除右子树中的最小值
	}
	}
	return node; //返回当前节点
}
