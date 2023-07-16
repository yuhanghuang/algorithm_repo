from operator import le
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#二分法的查找
# 
# @param nums int整型一维数组 
# @param target int整型 
# @return int整型
#
class Solution:
    def search(self , nums: List[int], target: int) -> int:
        left=0
        right=len(nums)
        if(len(nums)==0):
            return -1
        if(right==left+1):
            if(nums[left]==target):
                return 0
            else:
                return -1
        right=len(nums)-1
        mid=(left+right)//2
        while(left<=right):
            if(right==left+1):
                if(nums[left]==target):
                    return left
                elif(nums[right]==target):
                    return right
                else:
                    return -1
            if(nums[mid]<target):
                print(mid)
                left=mid
                mid=(left+right)//2
                continue
            if(nums[mid]==target):
                return mid
            if(nums[mid]>target):
                print(mid)
                right=mid
                mid=(left+right)//2
                continue
        return -1   
