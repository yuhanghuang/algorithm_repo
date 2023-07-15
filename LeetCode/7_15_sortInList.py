# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 the head node
# @return ListNode类
#
class Solution:
    def sortInList(self , head: ListNode) -> ListNode:
        p=head
        a=[]
        while(p!=None):
            a.append(p.val)
            p=p.next
        # print(a)
        a.sort()
        # print(a)
        p=head
        i=0
        while(p!=None):
            p.val=a[i]
            i+=1
            p=p.next
        return head
        # write code here