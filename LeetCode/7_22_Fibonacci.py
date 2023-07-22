#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param n int整型 
# @return int整型
#
class Solution:
    def Fibonacci(self , n: int) -> int:
        if(n<=2):
            return 1
        else:
            # return self.Fibonacci(n-1)+self.Fibonacci(n-2)
            prev=1
            curr=2
            for _ in range(3,n):
                prev,curr=curr,prev+curr
        return curr
        # write code here

if __name__=="__main__":
    sl=Solution()
    print(sl.Fibonacci(4))