# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @return ListNode类
#
class Solution:
    def oddEvenList(self , head: ListNode) -> ListNode:
        a1=[]
        a2=[]
        count=0
        p=head
        i1=0
        i2=0
        while(p!=None):
            if(count%2==0):
                # a1[i1]=p.val
                a1.append(p.val)
                i1+=1
                p=p.next
                count+=1
            else:
                # a2[i2]=p.val
                a2.append(p.val)
                i2+=1
                p=p.next
                count+=1
        print(a1)
        print(a2)
        list1=a1+a2
        index=0
        print(list1)
        p=head
        while(p!=None):
            p.val=list1[index]
            index+=1
            p=p.next
        return head
        # write code here