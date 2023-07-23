from math import cos
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param cost int整型一维数组 
# @return int整型
#
class Solution:
    def minCostClimbingStairs(self , cost: list[int]) -> int:
        # write code here
        dp=[]
        for _ in range(len(cost)+1):
            dp.append(0)
        print(dp)
        if len(cost)<=1:
            return cost[0]
        dp[0]=0
        dp[1]=min(0,dp[0])
        for i in range(2,len(cost)+1):
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
        return dp[len(cost)]

