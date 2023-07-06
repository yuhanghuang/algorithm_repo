'''给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的正偶数之和，且拆分出来的正偶数数目 最多 。

比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的正偶数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。
请你返回一个整数数组，表示将整数拆分成 最多 数目的正偶数数组。如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返回这些整数。

'''
class Solution:
    def maximumEvenSplit(self, finalSum: int) -> list[int]:
        res=[]
        if finalSum % 2>0:
            return res
        data=2
        while finalSum-data>0:
            finalSum=finalSum-data
            res.append(data)
            data=data+2
        if finalSum-data>=0:
            res.append(finalSum)
        if finalSum-data<0:
            del res[-1]
            res.append(data-2+finalSum)
        return res
    
if __name__ == '__main__':
    w = Solution()
    result=[]
    number = input("input:")
    result=w.maximumEvenSplit(int(number))
    print("长度为")
    print(len(result))
    print("元素为")
    for element in result:
        print(element)
