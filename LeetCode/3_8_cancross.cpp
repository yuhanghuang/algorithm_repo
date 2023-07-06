/*
一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。
给你石子的位置列表 stones（用单元格序号 升序 表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。开始时， 青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃 1 个单位（即只能从单元格 1 跳至单元格 2 ）。
如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1 个单位。 另请注意，青蛙只能向前方（终点的方向）跳跃。
输入：stones = [0,1,3,5,6,8,12,17]
输出：true
解释：青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2 个单位到第 4 块石子, 然后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 个石子（即最后一块石子）。
https://leetcode.cn/problems/frog-jump/solution/c-ji-yi-hua-sou-suo-dong-tai-gui-hua-by-uq2pl/
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][speed]：表示能否以speed的速度，到达第i个石头
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int speed = stones[i] - stones[j];
                if(speed <= 0 || speed > j+1) 
                    continue;
                    
                dp[i][speed] = dp[j][speed-1] || 
                    dp[j][speed] || dp[j][speed+1];

                if(dp[n-1][speed] == 1)
                    return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    unordered_map<int, unordered_set<int>> visited;
    unordered_set<int> stone_pos;
    int done;
    bool dfs(int prv_pos, int speed) {
        int cur_pos = prv_pos + speed;

        if(speed < 0 || !stone_pos.count(cur_pos))
            return false;
        if(visited[prv_pos].count(speed))
            return false;
        visited[prv_pos].insert(speed);

        if(cur_pos == done)
            return true;
        
        return dfs(cur_pos, speed-1) || 
            dfs(cur_pos, speed) || dfs(cur_pos, speed+1);   
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        stone_pos = unordered_set<int>(stones.begin(), stones.end());
        done = stones.back();

        return dfs(0, 1);
    }
};

class Solution3 {
public:
    unordered_set<int> s;
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
    bool dfs(vector<int>& stones, int k, int idx)
    {
        int key = idx * 1000 + k;
        if (s.count(key) != 0) {
            return false;
        } else {
            s.insert(key);
        }

        for (int i = idx + 1; i < stones.size(); ++i)
        {
            int gap = stones[i] - stones[idx];
            if (gap < k - 1) {
                continue;
            } else if (gap > k + 1) {
                break;
            } else {
                if (dfs(stones, gap, i)) {
                    return true;
                }
            }
        }
        return idx == stones.size() - 1;
    }
};


