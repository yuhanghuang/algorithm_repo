# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        p1=head
        end=head
        p2=p1
        count=0
        result=p1
        recor=set()
        # p2=head+2
        if(p1==None):
            return None
        while(p1!=None):
            if(p2.next==p1):
                print(p2.val)
                print(p1.val)
                result=p2
                break
            elif(count>=10000):
                return None
            elif(p2==None or p2.next==None or p2.next.next==None):
                return None
            else:
                p1=p1.next
                p2=p2.next.next
                count=count+1
        print(result.val)
        p3=result
        print("111111")
        while(p3.next!=result):
            print(p3.val)
            recor.add(p3)
            p3=p3.next
        recor.add(p3)
        print("44444")
        # print(ans.val)
        print(p3.val)
        # print(recor)
        while(end!=result):
            if end in recor:
                break
            end=end.next
        print(end.val)
        ans=end
        p4=head
        count1=0
        while(p4!=ans):
            p4=p4.next
            count1=count1+1
        return p4