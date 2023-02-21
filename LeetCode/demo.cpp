/*给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边\
界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(2,0)));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(grid[i-1][j-1]==0)
                {
                    continue;
                }
                else
                {
                    dp[i][j][0] = dp[i][j-1][0]+1;
                    dp[i][j][1] = dp[i-1][j][1]+1;

                }
            }
        }

    int maxsize=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int currsize=min(dp[i][j][0],dp[i][j][1]);
            if(currsize <= maxsize)
            {
                continue;
            }
            for(;currsize>maxsize;currsize--)
            {
                if(dp[i][j-currsize+1][1]>=currsize && dp[i-currsize+1][j][0]>=currsize)
                {
                    maxsize=currsize;
                    break;
                }
            }
        }
    }
    return maxsize*maxsize;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> grid={{1,1,1},{1,0,1},{1,1,1}};
    // vector<vector<int>> grid(3, std::vector<int>(3, 0));
    // grid[0]={1,1,1};
    // grid[1]={1,0,1};
    // grid[2]={1,1,1};
    // printf(sl.largest1BorderedSquare(grid));
    printf("%d\n",sl.largest1BorderedSquare(grid));
    system("pause");

    
}