#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param m int整型 
# @param n int整型 
# @return int整型
#
class Solution:
    def uniquePaths(self , m: int, n: int) -> int:
        # write code here
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=0
        for i in range(n):
            dp[0][i]=1
        for i in range(m):
            dp[i][0]=1
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        print(dp)
        return dp[m-1][n-1]