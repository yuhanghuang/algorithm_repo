/*有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。

不过我们在使用它时有个约束，就是使得投掷骰子时，连续 掷出数字 i 的次数不能超过 rollMax[i]（i 从 1 开始编号）。

现在，给你一个整数数组 rollMax 和一个整数 n，请你来计算掷 n 次骰子可得到的不同点数序列的数量。

假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 模 10^9 + 7 之后的结果。
*/

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // vector<vector<int>> ans(6^n, vector<int>(6));
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(6,vector<int>(16,0)));
        int i,j,k,nk;
        for(int s=1;s<=6;s++)
        {
            dp[0][s][1]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=6;j++)
            {
                for(int k=1;k<=15;k++)
                {
                    if(dp[i-1][j][k]!=0)
                    {
                        for(nk=0;nk<6;nk++)
                        {
                            if(nj==j && k+1<rollMax[j])
                            {
                                dp[i][nj][k+1]=dp[i][nj][k+1]+dp[i-1][j][k];
                            }
                            else
                            {
                                dp[i][nj][1]=dp[i][nj][1]+dp[i-1][j][k];
                            }
                            
                        }
                    }
                }
            }
        }
    int sum=0;
    for(int t=1;t<=6;t++)
    {
        for(int s=0;s<=15;s++)
        {
            sum=sum+dp[n][t][s];
        }
    }

    return sum;
    }
};