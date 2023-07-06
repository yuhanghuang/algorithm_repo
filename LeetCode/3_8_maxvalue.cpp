#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(200,vector<int>(200,0));
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        int ans=0;
        // dp[grid.size()-1][grid[0].size()-1]=grid[0][0];
        dp[0][0]=grid[0][0];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 && j>=1)
                {
                    dp[0][j]=grid[i][j]+dp[0][j-1];
                }
                if(j==0 && i>=1)
                {
                    dp[i][0]=grid[i][j]+dp[i-1][0];
                }
                if(i>=1 && j>=1)
                {
                    dp[i][j]=grid[i][j]+max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
        }
        return dp[m][n];
        // for(int i=m;i>=0;i++)
        // {
        //     for(int j=n;j>=0;j++)
        //     {
        //         if(grid[i-1][j]>=grid[i][j-1])
        //         {
        //             ans+=grid[i-1][j];
        //             dp[i-1][j]=1;

        //         }
        //         else
        //         {
        //             ans+=grid[i][j-1];
        //             dp[i][j-1]=1;
        //         }
                       
        //     }
        // }[1,3,1],[1,5,1],[4,2,1]

    }
    };
    int main()
    {
        Solution sl;
        vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
        cout<<sl.maxValue(grid);
    }
