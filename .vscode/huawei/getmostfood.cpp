/*主办方设计了一个获取食物的游戏。游戏的地图由N个方格组成，每个方格上至多2个传送门，通过传送门可将参与者传送至指定的其它方格。同时，每个方格上标注了三个数字:
(1)第一个数字id:代表方格的编号，从0到N-1，每个方格各不相同(2)第二个数字parent-id:代表，parent-id的方格可以通过传送门传送到当前方格(-1则表示没有任何格以通过传送门传送到此方格，这样的方格在地图中有且仅有一个)
(3)第三个数字value:取值在[100，100]的整数值，正整数代表参与者得到相应数值单位的食物，负整数代表失去相应数值单位的食物(参与者可能存在临时持有食物为负数的情况)，0则代表无变化。
此外，地图设计时保证了参与者不可能到达相同的方格两次，并且至少有一个方格的value是正整数
3
T88101
游戏开始后，参与者任意选择一个方格作为出发点，当遇到下列情况之-
退出游戏:
(1)参与者当前所处的方格无传送门;
(2)参与者在任意方格上主动宣布退出游戏
请计算参与者退出游戏后，最多可以获得多少单位的食物。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node {
public:
  // 构造函数，初始化数据域和指针数组
  Node(int data) {
    this->data = data;
    for (int i = 0; i < MAX_CHILDREN; i++) {
      this->children[i] = nullptr;
    }
  }
  Node * next;

  // 数据域，存储节点的值
  int data;
  int value;
  int parent;

  // 指针数组，存储指向子节点的指针
  static const int MAX_CHILDREN = 2; // 假设每个节点最多有2个子节点
  Node* children[MAX_CHILDREN];
};

// 定义树类
class Tree {
public:
  // 构造函数，初始化根节点
  Tree(int root_data) {
    this->root = new Node(root_data);
  }
  // 根节点，指向树的第一个节点
  Node* root;
};
int main()
{
    int num;
    cin>>num;
    vector<int> res[num];
    int n1,n2,n3;
    int line=0;
    
    while(line<num)
    {
        cin>>n1>>n2>>n3;
        res[line].push_back(n1);
        res[line].push_back(n2);
        res[line].push_back(n3);
        line++;
    }
    // return res[0][1];
    for(int i=0;i<num;i++)
    {
        if(res[i][2]==-1)
        {
            Node root(res[i][0]);
            root.parent=res[i][1];
            root.value=res[i][2];
            root.data=res[i][1];
        }
        else
        {
            Node temp = Node(res[i][1]);

        }

    }

}
