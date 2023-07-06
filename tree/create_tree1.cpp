请使用C++根据输入实现一个树的构造

树是一种非线性的数据结构，它由一个根节点和若干个子树组成。树的构造是指根据给定的输入，创建一个对应的树对象。在C++中，可以使用类来定义树的结构和操作，例如：

// 定义树节点类
class TreeNode {
public:
  // 节点值
  int val;
  // 左右子节点指针
  TreeNode* left;
  TreeNode* right;
  // 构造函数
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 定义树类
class Tree {
public:
  // 根节点指针
  TreeNode* root;
  // 构造函数
  Tree() : root(nullptr) {}
  // 根据输入构造树的函数
  void buildTree(vector<int>& input) {
    // 如果输入为空，返回空树
    if (input.empty()) return;
    // 创建一个队列，用于层次遍历
    queue<TreeNode*> q;
    // 创建根节点，并将其入队
    root = new TreeNode(input[0]);
    q.push(root);
    // 记录当前处理的输入下标
    int index = 1;
    // 当队列不为空时，循环处理每个节点
    while (!q.empty()) {
      // 出队一个节点
      TreeNode* node = q.front();
      q.pop();
      // 如果还有剩余的输入，且不为-1，表示有左子节点
      if (index < input.size() && input[index] != -1) {
        // 创建左子节点，并将其入队
        node->left = new TreeNode(input[index]);
        q.push(node->left);
      }
      // 下标加一
      index++;
      // 如果还有剩余的输入，且不为-1，表示有右子节点
      if (index < input.size() && input[index] != -1) {
        // 创建右子节点，并将其入队
        node->right = new TreeNode(input[index]);
        q.push(node->right);
      }
      // 下标加一
      index++;
    }
  }
};