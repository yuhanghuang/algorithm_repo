#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param array int整型一维数组 
# @return int整型
#
class Solution:
    def FindGreatestSumOfSubArray(self , array: list[int]) -> int:
        # write code here
        if not array:
            return 0
        if len(array)==1:
            return array[0]
        
        dp=[0]*len(array)
        print(dp)
        for i in range(len(array)):
            dp[i]=array[i]
        print(dp)
        temp=0
        for i in range(1,len(array)):
            dp[i]=max(dp[i],dp[i-1]+array[i])
            print(dp[i])
        return max(dp)