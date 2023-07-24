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
    def LCS(self, s1: str, s2: str) -> str:
        m, n = len(s1), len(s2)
        dp = [[""] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1]
                else:
                    if len(dp[i - 1][j]) > len(dp[i][j - 1]):
                        dp[i][j] = dp[i - 1][j]
                    else:
                        dp[i][j] = dp[i][j - 1]
        if dp[m][n] == "":
            return "-1"
        else:
            return dp[m][n]

        # write code here
        # n=len(s2)
        # m=len(s1)
        # dp=[]
        # result=[['']*(n) for _ in range(m)]
        # print(result)
        # for _ in range(m):
        #     temp=[]
        #     for _ in range(n):
        #         temp.append(0)
        #     dp.append(temp)
        # for i in range(0,m):
        #     if(s1[i]==s2[0]):
        #         dp[i][0]=1
        # for i in range(0,n):
        #     if(s1[0]==s2[i]):
        #         dp[0][i]=1
        # print(dp)
        # for i in range(1,m):
        #     for j in range(1,n):

        #         if s1[i]==s2[j]:
        #             dp[i][j]=dp[i-1][j-1]+1
        #             result[]
        #         else:
        #             dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        # print(dp)
        # print(dp[m-1][n-1])
        # i=m-1
        # j=n-1
        # lcs=""
        # while i>=0 and j>=0:
        #     if(s1[i]==s2[j]):
        #         lcs=s1[i]+lcs
        #         i-=1
        #         j-=1
        #     elif dp[i-1][j] > dp[i][j-1]:
        #         i-=1
        #     else:
        #         j-=1
        # if not lcs:
        #     return "-1"
        # return lcs
