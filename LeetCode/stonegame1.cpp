/*Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，排成一行；每堆都有 正 整数颗石子，数目为 piles[i] 。
游戏以谁手中的石子最多来决出胜负。石子的 总数 是 奇数 ，所以没有平局。
Alice 和 Bob 轮流进行，Alice 先开始 。 每回合，玩家从行的 开始 或 结束 处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中 石子最多 的玩家 获胜 。
假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回 true ，当 Bob 赢得比赛时返回 false*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
    int length=piles.size();
    vector<vector<int>> dp(length,vector<int>(length));
    for(int i=0;i<piles.size();i++)
    {
        dp[i][i] = piles[i];
    }

    for(int i=length-2;i>=0;i--)
    {
        for(int j=i+1;j<length;j++)
        {
            dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
        }
    }
    if(dp[0][length-1]>0)
        return true;
    else
        return false;
    }
};
int main()
{
    vector<int> arr={5,3,4,5};
    Solution sl;
    cout<<sl.stoneGame(arr);
}