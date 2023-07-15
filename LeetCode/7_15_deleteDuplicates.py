# class ListNode:

# from numpy import add
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
# @param head ListNode类 
# @return ListNode类
#
class Solution:
    def deleteDuplicates(self , head: ListNode) -> ListNode:
        a=set()
        p=ListNode(None)
        p.next=head
        a=dict()
        while(p.next!=None):
            if p.next.val in a:
                # print(p.next.val)
                # a.discard(p.next.val)
                # print(a)
                a[p.next.val]+=1
                p=p.next
                # temp=p.next.next
                # p.next=temp
            else:
                a[p.next.val]=1
                p=p.next
        print(a)   
        p=ListNode(None)
        p1=p
        # if(len(a)==0):
        #     return None
        for i in a:
            if(a[i]==1):
                print(i)
                temp=ListNode(i)
                p.next=temp
                p=p.next
        return p1.next
