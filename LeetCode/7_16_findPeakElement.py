#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#峰值的查找
# 
# @param nums int整型一维数组 
# @return int整型
#
class Solution:
    def findPeakElement(self , nums: List[int]) -> int:
        if(len(nums)==1):
            return 0
        if(len(nums)==2):
            if(nums[1]>nums[0]):
                return 1
            else:
                return 0
        for i in range(len(nums)-2):
            if(nums[i]<nums[i+1] and nums[i+2]<nums[i+1]):
                return i+1
        # print(i)
        if(nums[len(nums)-1]>nums[len(nums)-2]):
            return len(nums)-1
        else:
            return 0
        return 0
        # write code here