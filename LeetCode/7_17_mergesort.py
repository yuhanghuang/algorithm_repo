class Solution:
    def merge_sort(self,array):
        if(len(array)<=1):
            return array
        mid=len(array)//2
        left_half=array[:mid]
        right_half=array[mid:]
        left_halfs=self.merge_sort(left_half)
        right_halfs=self.merge_sort(right_half)
        return self.merge(left_halfs,right_halfs)

    def merge(self,left_half,right_half):
        merged=[]
        left_index=0
        right_index=0
        while(left_index<len(left_half) and right_index<len(right_half)):
            if(left_half[left_index]<right_half[right_index]):
                merged.append(left_half[left_index])
                left_index+=1
            else:
                merged.append(right_half[right_index])
                right_index+=1
        merged.extend(left_half[left_index:])
        merged.extend(right_half[right_index:])
        return merged
if __name__=="__main__":
    sl=Solution()
    array=[1,6,8,3,5,2,0,9]
    print(sl.merge_sort(array))
    # array1=sl.merge_sort(array)
    # for i in array1:
    #     print(i)



