#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
    	int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
    	// vector<vector<vector<int>>> dp(n,vector<>);
    	// 一维vector初始化
    	vector<int> dp1(4,0);
    	//二维vector初始化
    	vector<vector<int>> dp2(4,vector<int>(5,0));
    	//三维vector初始化
    	vector<vector<vector<int>>> dp3(4,vector<vector<int>>(5,vector<int>(6,0)));
    	vector<vector<vector<int>>> dp4(4,vector<vector<int>>(5,vector<int>(6,0)));
    	// int dp [n][n][n];
    	// int sum[i][j];
    	vector<int> sums(n+1,0);
    	vector<vector<int>> dp(n,vector<int>(n,0));
    	for(int i=1;i<=n;i++)
    	{
    		sums[i]=sums[i-1]+stones[i-1];
    	}
    	for (int len = k; len <= n; ++len) { // 枚举区间长度
            for (int i = 1; i + len - 1 <= n; ++i) { // 枚举区间起点
                int j = i + len - 1;
                dp[i][j] = 999999;
                for (int p = i; p < j; p += k - 1) {  // 枚举分界点
                    dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
                }
                if ((j - i) % (k - 1) == 0) dp[i][j] += sums[j] - sums[i - 1];
            }
        }
    	return dp[1][n];

    }
};

int main()
{
    Solution sl;
    vector<int> stones={3,2,4,1};
    cout<<sl.mergeStones(stones,2);
}