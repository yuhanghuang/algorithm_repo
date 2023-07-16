class merge:
    def merge1(self,nums,left,mid,right):
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