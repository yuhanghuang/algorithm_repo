#include<iostream>
#include<vector>
using namespace std;

// 本题的思路是使用动态规划，对于每个节点，计算以它为根的子树的节点数和最优方案的数量。
// 然后遍历所有的边，计算删除该边后的|A-B|值，找出最小的值和对应的方案数量。
// 时间复杂度是O(n)，空间复杂度是O(n)。

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005; // 定义最大节点数
vector<int> adj[MAXN]; // 邻接表存储树
int n; // 节点数
// int size[100005]; // size[i]表示以i为根的子树的节点数
vector<int> sizes(MAXN,-1);
int ans[MAXN]; // ans[i]表示以i为根的子树的最优方案的数量
int min_diff = MAXN; // 最小的|A-B|值
int cnt = 0; // 最小|A-B|值对应的方案数量

// 动态规划函数，计算每个节点的size和ans
void dp(int u, int p) {
    sizes[u] = 1; // 初始化u的size为1
    ans[u] = 1; // 初始化u的ans为1
    for (int v : adj[u]) { // 遍历u的所有子节点
        if (v == p) continue; // 跳过父节点
        dp(v, u); // 递归计算v的size和ans
        sizes[u] += sizes[v]; // 更新u的size
        ans[u] *= ans[v]; // 更新u的ans
    }
}

// 主函数
int main() {
    cin >> n; // 输入节点数
    for (int i = 0; i < n - 1; i++) { // 输入n-1条边
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t); // 添加s到t的边
        adj[t].push_back(s); // 添加t到s的边
    }
    dp(1, 0); // 从根节点开始动态规划，假设根节点是1，父节点是0
    for (int u = 1; u <= n; u++) { // 遍历所有节点
        for (int v : adj[u]) { // 遍历u的所有子节点
            if (v < u) continue; // 跳过重复计算的边
            int diff = abs(sizes[v] - (n - sizes[v])); // 计算删除u到v的边后的|A-B|值
            if (diff < min_diff) { // 如果比当前最小值小，更新最小值和方案数量
                min_diff = diff;
                cnt = ans[u] * ans[v];
            } else if (diff == min_diff) { // 如果和当前最小值相等，累加方案数量
                cnt += ans[u] * ans[v];
            }
        }
    }
    cout << min_diff << " " << cnt << endl; // 输出最小值和方案数量
    return 0;
}