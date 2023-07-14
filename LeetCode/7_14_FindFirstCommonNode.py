# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#
# 
# @param pHead1 ListNode类 
# @param pHead2 ListNode类 
# @return ListNode类
#
class Solution:
    def FindFirstCommonNode(self , pHead1 , pHead2 ):
        record1=set()
        p=pHead1
        while(p!=None):
            record1.add(p)
            print(p.val)
            p=p.next
        p2=pHead2
        while(p2!=None):
            if p2 in record1:
                return p2
            p2=p2.next
        return None
        # write code here