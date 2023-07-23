from re import S
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# longest common subsequence
# @param s1 string字符串 the string
# @param s2 string字符串 the string
# @return string字符串
#
class Solution:
    def LCS(self , s1: str, s2: str) -> str:
        # write code here 
        n=len(s2)
        m=len(s1)
        dp=[]
        result=[]
        for _ in range(m):
            temp=[]
            for _ in range(n):
                temp.append(0)
            dp.append(temp)
        for i in range(0,m):
            if(s1[i]==s2[0]):
                dp[i][0]=1
        for i in range(0,n):
            if(s1[0]==s2[i]):
                dp[0][i]=1
        print(dp)
        for i in range(1,m):
            for j in range(1,n):
            
                if s1[i]==s2[j]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        print(dp)
        # return dp[m-1][n-1]
        i=m-1
        j=n-1
        lcs=""
        while i>=0 and j>=0:
            if(s1[i-1]==s2[j-1]):
                lcs=s1[i-1]+lcs
                i-=1
                j-=1
            elif dp[i-1][j] > dp[i][j-1]:
                i-=1
            else:
                j-=1
        return lcs

        

