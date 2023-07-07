# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
                # write code here
        if(l1==None and l2==None):
            return None
        temp=ListNode(None)
        temp1=temp
        while(l1!=None and l2!=None):
            if(l1.val>l2.val):
                temp.next=l2
                l2=l2.next
                temp=temp.next
            else:
                temp.next=l1
                l1=l1.next
                temp=temp.next
        if(l1!=None):
            temp.next=l1
            return temp1.next
        else:
            temp.next=l2
            return temp1.next
        # return temp1.next