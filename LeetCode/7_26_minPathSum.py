#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param matrix int整型二维数组 the matrix
# @return int整型
#
class Solution:
    def minPathSum(self , matrix: list[list[int]]) -> int:
        # write code here
        dp=[[0]*len(matrix[0]) for _ in range(len(matrix))]
        # print(dp)
        m=len(matrix[0])
        n=len(matrix)
        dp[0][0]=matrix[0][0]
        for i in range(1,m):
            dp[0][i]=matrix[0][i]+dp[0][i-1]
        for i in range(1,n):
            dp[i][0]=matrix[i][0]+dp[i-1][0]
        print(dp)
        for i in range(1,n):
            for j in range(1,m):
                dp[i][j]=min(dp[i-1][j]+matrix[i][j],dp[i][j-1]+matrix[i][j])
        return dp[n-1][m-1]