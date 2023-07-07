from threading import currentThread
# class ListNode:

from numpy.ma import count
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @param k int整型 
# @return ListNode类
#
class Solution:
    def reverseKGroup(self , head: ListNode, k: int) -> ListNode:
        # write code here
        dummy=p0=ListNode(None)
        dummy.next=head
        # p0.next=head
        count=0
        curr=p0.next
        while(curr):
            count+=1
            curr=curr.next   
        while(count>=k):
            count-=k
            curr=p0.next
            pre=None
            k1=k
            while(k1):
                nxt=curr.next
                curr.next=pre
                pre=curr
                curr=nxt
                k1=k1-1

            # for _ in range(k):
            #     nxt=curr.next
            #     curr.next=pre
            #     pre=curr
            #     curr=nxt
            nxt=p0.next
            p0.next.next=curr
            p0.next=pre
            p0=nxt
        return dummy.next

