from mergedemo import merge
class Solution:
    def reversePairs(self, nums: list[int]) -> int: 
        def merge_sort(nums,left,right):
            if(right<=left):
                return 0
            mid=(left+right)//2
            cnt_l=merge_sort(nums,left,mid)
            cnt_r=merge_sort(nums,mid+1,right)
            # cnt_c=self.merge(nums,left,mid,right)
            obj=merge()
            cnt_c=obj.merge1(nums,left,mid,right)
            return cnt_l+cnt_r+cnt_c
        return merge_sort(nums,0,len(nums)-1)
    def merge(self,nums,left,mid,right):
        tmp,count=[],0
        l1,l2=left,mid+1
        while l1<=mid and right>=l2:
            if(nums[l1]<nums[l2]):
                l1+=1
                tmp.append(nums[l1])
            else:
                tmp.append(nums[l2])
                l2+=1
                count+=(mid-l1+1)
        if l1<=mid:
            tmp.extend(nums[l1:mid+1])
        else:
            tmp.extend(nums[mid:right+1])
        nums[left:right+1]=tmp[:]
        return count
        
# 在Python类中，一个函数可以通过使用self关键字来调用类的另一个函数。self表示类的实例本身，可以在类的方法中使用它来访问该实例的属性和调用其他方法。
if __name__=="__main__":
    nums=[7,5,6,4]
    sl=Solution()
    print("*****")
    print(sl.reversePairs(nums))

                

                
            




