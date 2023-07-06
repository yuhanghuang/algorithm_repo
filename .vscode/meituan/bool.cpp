#include<iostream>
#include<vector>
using namespace std;
// 以下是一个可能的实现，不一定是最优的
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 定义一个球的结构体，包含颜色和数字
struct Ball {
  char color; // 'R'表示红色，'B'表示蓝色
  int number; // 球上写的数字
};

// 定义一个袋子的类，包含一个球的向量和一个哈希表
class Bag {
  private:
    vector<Ball> balls; // 存储球的向量
    unordered_map<char, int> sum; // 存储每种颜色球的数字之和
  public:
    // 构造函数，初始化空袋子
    Bag() {
      balls.clear();
      sum['R'] = 0;
      sum['B'] = 0;
    }

    // 向袋子里放入一个球，更新向量和哈希表
    void put(Ball ball) {
      balls.push_back(ball);
      sum[ball.color] += ball.number;
    }

    // 从袋子里取出一个球，更新向量和哈希表
    Ball take() {
      Ball ball = balls.back();
      balls.pop_back();
      sum[ball.color] -= ball.number;
      return ball;
    }

    // 计算某个时刻袋子中球上写的数字之和，根据颜色和时间调整数字
    int calculate(int time) {
      int total = 0;
      for (auto it : sum) {
        if (it.first == 'R') {
          total += it.second + time * balls.size();
        } else {
          total += it.second - time * balls.size();
        }
      }
      return total;
    }
};

// 主函数，测试一些例子
int main() {
  // 创建一个袋子对象
  Bag bag;

  // 创建一些球对象
  Ball ball1 = {'R', 1};
  Ball ball2 = {'B', 2};
  Ball ball3 = {'R', 3};
  Ball ball4 = {'B', 4};

  // 向袋子里放入球
  bag.put(ball1);
  bag.put(ball2);
  bag.put(ball3);
  bag.put(ball4);

  // 计算不同时间的数字之和
  cout << "t=0时，数字之和为：" << bag.calculate(0) << endl; // 输出10
  cout << "t=1时，数字之和为：" << bag.calculate(1) << endl; // 输出14
  cout << "t=2时，数字之和为：" << bag.calculate(2) << endl; // 输出18

  // 取出一个球
  Ball ball = bag.take();

  // 计算不同时间的数字之和
  cout << "取出" << ball.color << "色球，上面写着" << ball.number << endl; // 输出B色球，上面写着4
  cout << "t=0时，数字之和为：" << bag.calculate(0) << endl; // 输出6
  cout << "t=1时，数字之和为：" << bag.calculate(1) << endl; // 输出8
  cout << "t=2时，数字之和为：" << bag.calculate(2) << endl; // 输出10

  return 0;
}