# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, head1: ListNode, head2: ListNode) -> ListNode:
        count=0
        result=0
        p1=head1
        if(head1.val==0 and head2.val==0 and head2.next==None and head1.next==None):
            return ListNode(0)
        while(p1!=None):
            count+=1
            p1=p1.next
        p1=head1
        i=1
        while(p1!=None):
            result+=p1.val*(10**(count-i))
            i+=1
            p1=p1.next
        print(result)

        p1=head2
        count=0
        while(p1!=None):
            count+=1
            p1=p1.next
        p1=head2
        result1=0
        i=1
        while(p1!=None):
            result1+=p1.val*(10**(count-i))
            i+=1
            p1=p1.next
        print(result1)
        end=result1+result
        print(end)
        temp=ListNode(None)
        ii=0
        cc=[]
        while(end>=1):
            ii+=1
            temp1=end%10
            print(temp1)
            end=(end-temp1)//10
            # print("***")
            # print(end)
            # end=end-10*temp1
            cc.append(temp1)
            # print(end)
        # print(cc)
        pp=ListNode(1)
        p33=pp
        for i in range(len(cc)):
            temps=ListNode(cc[len(cc)-i-1])
            pp.next=temps
            pp=temps
            # print(pp.val)
        return p33.next