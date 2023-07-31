#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param A string字符串
# @return int整型
#
class Solution:
    def getLongestPalindrome(self, s: str) -> int:
        # write code here
        n = len(s)
        if n == 0:
            # return ""
            return 0

        dp = [[False] * n for _ in range(n)]
        max_length = 1
        start = 0

        # 单个字符是回文串
        for i in range(n):
            dp[i][i] = True

        # 判断长度为 2 的子串是否为回文串
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                max_length = 2
                start = i

        # 判断长度大于 2 的子串是否为回文串
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    max_length = length
                    start = i

        return len(s[start : start + max_length])
