class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        def merge_sort(left,right):
            if(left>=right):
                return 0
            mid=(left+right)//2
            res=merge_sort(left,mid)+merge_sort(mid+1,right)
            i=left
            j=mid+1
            tmp[left:right+1]=nums[left:right+1]
            for k in range(left,right+1):
                if(i==mid+1):
                    nums[k]=tmp[j]
                    j+=1
                # print(tmp)
                elif(j==right+1 or tmp[i]<=tmp[j]):
                # elif j == right + 1 or tmp[i] <= tmp[j]:
                    i+=1
                    nums[k]=tmp[i]
                else:
                    nums[k]=tmp[j]
                    j+=1
                    res+=mid-i+1
            return res
        # tmp=[]
        # tmp = [0] * len(nums)
        tmp=[]
        return merge_sort(0,len(nums)-1)
if __name__=="__main__":
    sl=Solution()
    print(sl.reversePairs([7,5,6,4]))
