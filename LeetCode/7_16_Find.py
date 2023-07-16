from pickle import TRUE
# from operator imporFALSE, t le
from re import search
#二维数组的查找
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param target int整型
# @param array int整型二维数组
# @return bool布尔型
#
class Solution:
    def Find(self, target: int, matrix: List[List[int]]) -> bool:
        # for row in matrix:
        #     for element in row:
        #         if element == target:
        #             return True
        # return False
        row = len(matrix)
        col= len(matrix[0])
        x=0
        y=col-1
        while(x<row and y>=0):
            if(matrix[x][y]==target):
                return True
            if(matrix[x][y]>target):
                y=y-1
            else:
                x=x+1
        return False
            
        # nums=row*col-1
        # left=0
        # right=nums-1
        # # print(left)
        # # print(right)
        # while(left<right):
        #     if(right==left+1):
        #         print(array[left//col][left%col])
        #         if(array[left//col][left%col]==target or array[left//col][(left%col)+1]==target):
        #             return True
        #         else:
        #             return False
        #     mid=(left+right)//2
        #     mid_row=mid//col
        #     mid_col=mid%col
        #     mid_val=array[mid_row][mid_col]
        #     print(mid_val)
        #     if(mid_val<target):
        #         left=mid+1
        #     elif(mid_val==target):
        #         return True
        #     else:
        #         right=mid-1

        # return False

