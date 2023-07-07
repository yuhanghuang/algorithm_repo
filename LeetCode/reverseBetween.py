# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
#         pre=None
#         curr=head
#         count=1
#         # print(head)
#         if(left==1 and right<left):
#             temp=head.next
#             print(temp)
#             next=temp.next
#             print(next)
#             temp.next=head
#             head.next=next
#             return temp
#         while(count<left):
#             # te=curr.next
#             # curr=next
#             curr=curr.next
#             count=count+1
#         # print(curr)
#         curr1=curr
#         while(count<=right):
#             next=curr.next
#             curr.next=pre
#             pre=curr
#             curr=next
#             count=count+1
#         # print(pre)
#         begin=head
#         print(begin)
#         while(begin.next!=curr1 and begin.next):
#             begin=begin.next
#         # print(curr)
#         begin.next=pre
#         curr1.next=curr
#         # print(begin)
#         # print(curr1.next)
#         return head
# 不要跳进递归（你的脑袋能压几个栈呀？），而是要根据刚才的函数定义，来弄清楚这段代码会产生什么结果：

class Solution:
    def __init__(self):
        self.successor = None
        
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # base case
        if left == 1:
            return self.reverseN(head, right)
        head.next = self.reverseBetween(head.next, left - 1, right - 1)
        return head

    def reverseN(self, head, n):
        if n == 1:
            self.successor = head.next
            return head
        last = self.reverseN(head.next, n-1)
        head.next.next = head
        head.next = self.successor
        return last
    

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        p0=dummy=ListNode(next=head)
        for i in range(left-1):
            p0=p0.next
        curr=p0.next
        pre=None
        for i in range(right-left+1):
            nxt=curr.next
            curr.next=pre
            pre=curr
            curr.next

        p0.next.next=curr
        p0.next=pre
        return dommy.next

    
