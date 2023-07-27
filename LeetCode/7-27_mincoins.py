#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 最少货币数
# @param arr int整型一维数组 the array
# @param aim int整型 the target
# @return int整型
#
class Solution:
    def minMoney(self , arr: list[int], aim: int) -> int:
        # write code here
        dp = [float('inf')] * (aim + 1)
        # dp[i]表示总数为i的最小数量
        dp[0] = 0
        print(dp)
        # 动态规划计算最少硬币数量
        for coin in arr:
            for i in range(coin, aim + 1):
                dp[i] = min(dp[i], dp[i - coin] + 1)
                # print(dp)
        if dp[aim] != float('inf'):
            return dp[aim]
        else:
            return  -1