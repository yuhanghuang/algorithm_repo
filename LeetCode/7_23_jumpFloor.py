#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param number int整型 
# @return int整型
#
class Solution:
    def jumpFloor(self , number: int) -> int:
        # write code here
        dp=[]
        if number<=1:
            return 1
        for _ in range(number):
            dp.append(0)
        print(dp)
        dp[0]=1
        dp[1]=2
        # print(len(dp))
        for i in range(2,number):
            dp[i]=dp[i-1]+dp[i-2]
        return dp[number-1]


        # for _ in range(4):
        #     temp=[]
        #     for _ in range(5):
        #         temp.append(0)
        #     dp.append(temp)
        # print(dp)
        # rows = 3
        # cols = 4
        # matrix = [[0 for _ in range(cols)] for _ in range(rows)]
        # print(matrix)

