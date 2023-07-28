#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 给定数组的最长严格上升子序列的长度。
# @param arr int整型一维数组 给定的数组
# @return int整型
#
class Solution:
    def LIS(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    

if __name__=="__main__":
    sl=Solution()
    print(sl.LIS([3,5,7,1,2,4,6,3,8,9,5,6]))

        # write code here
        # n=len(arr)
        # result=[]
        # if not arr:
        #     return 0
        # dp=[[0]*n for _ in range(n)]
        # # print(dp)
        # for i in range(n-1):
        #     temp=[]
        #     temp.append(arr[i])
        #     for j in range(i+1,n):
        #         if(arr[j]>temp[-1]):
        #             temp.append(arr[j])
        #             dp[i][j]=dp[i][j-1]+1
        #         else:
        #             if(arr[j]>min(temp)):
        #                 temp[-1]=arr[j]
        #                 dp[i][j]=dp[j][j-1]
        #     print(temp)
        #     result.append(len(temp))
        # print(dp)
        # return max(result)
