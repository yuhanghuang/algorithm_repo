//定义TreeNode类
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	//构造方法
	TreeNode(int val) {
		this.val = val;
		this.left = null;
		this.right = null;
}
}

//定义一个全局变量index，用来记录当前创建的节点的索引
int index = 0;

//定义一个方法，用来构造二叉树
TreeNode buildTree(int[] values, int[] parent) {
//如果values数组为空或者index超出范围，返回null
	if (values == null || values.length == 0 || index >= values.length) {
	return null;
}
	//创建一个新的节点，给它赋值
	TreeNode node = new TreeNode(values[index]);
	//将当前节点的索引存入parent数组
	parent[index] = -1; //假设当前节点是根节点，没有父节点
	//递增index
	index++;
	//递归地创建左子节点，并更新parent数组
	node.left = buildTree(values, parent);
	if (node.left != null) {
		parent[index - 1] = index - 2; //左子节点的父节点是当前节点
	}
	//递归地创建右子节点，并更新parent数组
	node.right = buildTree(values, parent);
	if (node.right != null) {
		parent[index - 1] = index - 2; //右子节点的父节点是当前节点
	}
	//返回当前节点作为二叉树的结果
	return node;
}
