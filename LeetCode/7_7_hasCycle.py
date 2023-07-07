# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # print(head)
        if(head==None):
            return False
        if(head.next==None):
            return False
        p1=head
        p2=p1
        while(p1!=None):
            p1=p1.next
            if(p2==None):
                return True
            if(p2.next==None):
                return False
            if(p2.next.next==None):
                return False
            p2=p2.next
            p2=p2.next
            if(p1==p2):
                return True
        return False
            

# class ListNode:


#     def __init__(self, x):
#         self.val = x
#         self.next = None

#
#
# @param head ListNode类
# @return bool布尔型
#
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # print(head)
        recor=set()
        while(head):
            if head in recor:
                return True
            recor.add(head)
            head=head.next
        return False
        
