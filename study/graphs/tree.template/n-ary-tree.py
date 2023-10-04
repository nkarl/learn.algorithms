#############################################################################
# class definition
#############################################################################
class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

    def addOne(self, node):
        self.children.append(node)

    def addMany(self, nodes):
        self.children += nodes

    def __str__(self):
        string = [c.value for c in self.children]
        return f"value:'{self.value}'\tchildren:{string}"


#############################################################################
# tree operations
#############################################################################
def find(n, target):
    if n.value == target:
        return n
    found = None
    for c in n.children:
        found = find(c, target)
        if found:
            return found
    return found


#############################################################################
# test
#############################################################################
root = Node('a')
b0, b1, b2, b3 = Node('b0'), Node('b1'), Node('b2'), Node('b3')
root.addMany([b0, b1, b2, b3])
c0, c1, c2, c3 = Node('c0'), Node('c1'), Node('c2'), Node('c3')
root.children[1].addMany([c0, c1, c2, c3])

print(root)
print(root.children[1])
