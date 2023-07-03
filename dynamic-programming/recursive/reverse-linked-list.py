class Node:
    self = {}

    def __init__(self, value=0):
        self.value = value
        self.next: Node | None = None

    def __str__(self) -> str:
        string = f"[{self.value}]"
        n = self.next
        i = 1
        while n:
            string += f"-> [{n.value}]"
            n = n.next
            i += 1
        return string


def makeList(nums: list[int]):
    head = Node(nums[0])
    n = head
    for i in nums[1:]:
        n.next = Node(i)
        n = n.next
    return head


def printList(node: Node | None):
    if node is None:
        return
    print(node.value, end=" ")
    printList(node.next)

def preOrder(node):
    if node.next is None:
        return f'{node.value}'
    return f"{node.value} {preOrder(node.next)}"

def postOrder(node):
    if node.next is None:
        return f'{node.value}'
    return f"{postOrder(node.next)} {node.value}"

def reverseList(head):
    node = head
    # nprev = node
    nprev, nnext = None, None
    while node:
        nnext = node.next
        node.next = nprev
        nprev = node
        node = nnext
    return nprev


head = makeList([0, 1, 2, 3, 4])
# print(head)
# print(postOrder(head))
print(preOrder(head))
head = reverseList(head)
printList(head)
