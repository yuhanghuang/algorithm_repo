#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# longest common substring
# @param str1 string字符串 the string
# @param str2 string字符串 the string
# @return string字符串
#
class Solution:
    def LCS(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)

    # 创建一个二维数组 dp，用于保存子问题的结果
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # 记录最长公共子串的长度和结束位置
        max_length = 0
        end_pos = 0

        # 动态规划计算最长公共子串的长度
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    if dp[i][j] > max_length:
                        max_length = dp[i][j]
                        end_pos = i
                else:
                    dp[i][j] = 0

        # 根据最长公共子串的长度和结束位置构造最长公共子串
        longest_substring = str1[end_pos - max_length : end_pos]

        return longest_substring

    # write code here
    # m=len(str1)
    # n=len(str2)
    # dp=[[""]*(n+1) for _ in range(m+1)]
    # for i in range(1,m+1):
    #     for j in range(1,n+1):
    #         if str1[i-1]==str2[j-1]:
    #             dp[i][j]=dp[i-1][j-1]+str1[i-1]
    #         else:
    #             if len(dp[i - 1][j]) > len(dp[i][j - 1]):
    #                 dp[i][j] = dp[i - 1][j]
    #             else:
    #                 dp[i][j] = dp[i][j - 1]
    # return dp[m][n]
