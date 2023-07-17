#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 比较版本号
# @param version1 string字符串 
# @param version2 string字符串 
# @return int整型
#
class Solution:
    def compare(self , version1: str, version2: str) -> int:
        m=len(version1)
        n=len(version2)
        i=0
        j=0
        while(i<m or j<n):
            x=0
            while(i<m and version1[i]!='.'):
                x=x*10+ord(version1[i])-ord('0')
                # print(x)
                i+=1
            i+=1
            y=0
            while(j<n and version2[j]!='.'):
                print(j)
                # print(n)
                print("-----")
                y=y*10+ord(version2[j])-ord('0')
                # print(y)
                j+=1
            j+=1
            if(x!=y):
                if(x>y):
                    return 1
                else:
                    return -1
        return 0

