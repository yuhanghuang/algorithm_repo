from itertools import count
from re import L
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @return ListNode类
#
class Solution:
    def deleteDuplicates(self , head: ListNode) -> ListNode:
        a=set()
        p=ListNode(None)
        p.next=head
        while(p.next!=None):
            if p.next.val in a:
                temp=p.next.next
                p.next=temp
            else:
                a.add(p.next.val)
                p=p.next
        return head