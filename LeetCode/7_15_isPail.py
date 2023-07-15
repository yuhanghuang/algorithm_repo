# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 the head
# @return bool布尔型
#
class Solution:
    def isPail(self , head: ListNode) -> bool:
        a=[]
        p=head
        while(p!=None):
            a.append(p.val)
            p=p.next
        if(len(a)%2==0):
            for i in range(len(a)//2):
                if(a[i]==a[len(a)-i-1]):
                    continue
                else:
                    return False
        else:
            for i in range(len(a)//2+1):
                if(a[i]==a[len(a)-i-1]):
                    continue
                else:
                    return False
        return True

        