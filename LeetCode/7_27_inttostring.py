# from copy import PyStringMap
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 解码
# @param nums string字符串 数字串
# @return int整型
#
class Solution:
    def solve(self, nums: str) -> int:
        m = len(nums)
        dp = [0] * m
        dp[0] = 1
        print(ord('3')-ord('0'))
        if m == 1:
            if nums[0] >= "1" and nums[0] <= "26":
                return 1
            else:
                return 0
        if m >= 2 and nums[0] <= "1" and nums[1]>'0':
            dp[1] = 2
        elif m >= 2 and nums[0] == "2" and "0" <= nums[1] <= "6":
            dp[1] = 2
        else:
            dp[1] = dp[0]
        if m <= 2:
            print(dp)
            return dp[1]
        for i in range(2, m):
            if(nums[i]=='0'):
                if(nums[i-1]>'2'):
                    return 0
                if(nums[i-1]=='0'):
                    return 0
                if(nums[i-1]=='1' or nums[i-1]=='2'):
                    dp[i]=dp[i-1]
            else:
                if(nums[i-1]=='2'):
                    if(nums[i]<='6'):
                        dp[i] = dp[i - 1] + dp[i - 2]
                    else:
                        dp[i]=dp[i-1]
                elif(nums[i-1]=='1'):
                    dp[i] = dp[i - 1] + dp[i - 2]
                else:
                    dp[i]=dp[i-1]
        return dp[m - 1]
