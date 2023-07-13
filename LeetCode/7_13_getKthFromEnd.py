# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        count=0
        p=head
        p1=p
        print("1111")
        while(p!=None):
            p=p.next
            count=count+1
        temp=count-k
        # print(temp)
        count=0
        while(count<temp and p1!=None):
            if(p1.next!=None):
                p1=p1.next
                count=count+1
        return p1
        # return head