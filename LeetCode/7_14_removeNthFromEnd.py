# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        count=0
        p=head
        q=head
        while(p!=None):
            p=p.next
            count+=1
        i=0
        print(count)
        if(n==1 and count==1):
            return None
        if(count<=n):
            return head.next
        while(i<count-n-1):
            q=q.next
            i=i+1
        end=q.next.next
        pre=q
        print(q.val)
        pre.next=end
        return head
