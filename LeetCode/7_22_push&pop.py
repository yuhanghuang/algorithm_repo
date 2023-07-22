# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        self.stack1.append(node)
        # write code here
    def pop(self):
        a=self.stack1.pop(0)
        return a
        # return xx