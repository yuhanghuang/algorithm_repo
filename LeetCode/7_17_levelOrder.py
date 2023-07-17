from collections import deque

# append的用法
# my_list = [1, 2, 3]
# my_list.append(4)
# print(my_list)  # 输出：[1, 2, 3, 4]

# my_list.append([5, 6, 7])
# print(my_list)  # 输出：[1, 2, 3, 4, [5, 6, 7]]


# extend的用法
# my_list = [1, 2, 3]
# my_list.extend([4, 5, 6])
# print(my_list)  # 输出：[1, 2, 3, 4, 5, 6]

# my_list.extend("hello")
# print(my_list)  # 输出：[1, 2, 3, 4, 5, 6, 'h', 'e', 'l', 'l', 'o']


# 在Python中，`deque`和`queue`模块中的`Queue`类是用于实现队列的两种不同方式。
'''
1. `deque`：
   - `deque`是`collections`模块中的一个类，提供了一个双端队列的数据结构。
   - 它支持在队列的两端进行快速的插入和删除操作。
   - `deque`可以通过`append`和`popleft`方法实现队列的先进先出（FIFO）特性。
   - 可以使用`deque`作为普通队列的替代，也可以用它实现栈、双端队列等数据结构。
   - `deque`是线程安全的，可以在多线程环境中使用。

   示例代码：
   ```python
   from collections import deque

   my_queue = deque()
   my_queue.append(1)
   my_queue.append(2)
   my_queue.append(3)

   while my_queue:
       item = my_queue.popleft()
       print(item)

   # 输出：
   # 1
   # 2
   # 3
   ```

2. `Queue`：
   - `Queue`是`queue`模块中的一个类，提供了一个线程安全的队列实现。
   - `Queue`类实现了线程间的安全通信，可用于在多线程编程中共享数据。
   - 它提供了多种队列实现，包括先进先出（FIFO）队列和后进先出（LIFO）队列。
   - `Queue`类具有阻塞和非阻塞的队列操作，可根据需求选择合适的队列类型。
   - 在多线程编程中，`Queue`常用于实现生产者-消费者模式。

   示例代码：
   ```python
   from queue import Queue

   my_queue = Queue()
   my_queue.put(1)
   my_queue.put(2)
   my_queue.put(3)

   while not my_queue.empty():
       item = my_queue.get()
       print(item)

   # 输出：
   # 1
   # 2
   # 3
   ```
'''

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def level_order_traversal(self,root):
        if root is None:
            return []

        queue = deque()
        queue.append(root)
        result = []

        while queue:
            level = []
            level_size = len(queue)

            for _ in range(level_size):
                # 先进先出
                node = queue.popleft()
                level.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(level)

        return result

if __name__=="__main__":
    # 创建二叉树
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    # 层序遍历二叉树
    sl=TreeNode()
    result = sl.level_order_traversal(root)
    print(result)

'''
在Python的`deque`对象中，`pop()`和`popleft()`都是用于删除并返回元素的方法。它们之间的区别在于删除的位置和方式。

以下是`deque.pop()`和`deque.popleft()`的区别：

1. `deque.pop()`：
   - `pop()`方法从右端（尾部）删除并返回`deque`中的最右侧元素。
   - 它是`deque`的默认行为，如果不指定索引位置，`pop()`方法将删除并返回最右侧的元素。
   - 这种操作遵循先进后出（LIFO）的原则。

   示例代码：
   ```python
   from collections import deque

   my_queue = deque([1, 2, 3, 4, 5])
   item = my_queue.pop()
   print(item)  # 输出：5
   print(my_queue)  # 输出：deque([1, 2, 3, 4])
   ```

   在上述示例中，通过调用`my_queue.pop()`方法，我们从右端删除并返回了最右侧的元素5。删除后，`my_queue`中仅剩下元素1、2、3和4。

2. `deque.popleft()`：
   - `popleft()`方法从左端（头部）删除并返回`deque`中的最左侧元素。
   - 它是以先进先出（FIFO）的方式删除元素，类似于队列的行为。
   - `popleft()`方法在删除左侧元素时的时间复杂度为O(1)，而删除右侧元素的时间复杂度为O(n)。

   示例代码：
   ```python
   from collections import deque

   my_queue = deque([1, 2, 3, 4, 5])
   item = my_queue.popleft()
   print(item)  # 输出：1
   print(my_queue)  # 输出：deque([2, 3, 4, 5])
   ```

   在上述示例中，通过调用`my_queue.popleft()`方法，我们从左端删除并返回了最左侧的元素1。删除后，`my_queue`中仅剩下元素2、3、4和5。

需要注意的是，`deque.pop()`和`deque.popleft()`方法都会直接修改原始的`deque`对象，并返回被删除的元素。如果尝试在空的`deque`对象上调用这些方法，将会引发`IndexError`异常。

总结：
- `deque.pop()`从右端删除并返回最右侧的元素，遵循先进后出（LIFO）原则。
- `deque.popleft()`从左端删除并返回最左侧的元素，遵循先进先出（FIFO）原则。

希望这个解释对你有帮助！如果你还有其他问题，请随时提问。
'''