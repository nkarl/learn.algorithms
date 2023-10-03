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
        return f"value:'{root.value}' children:{string}"


#############################################################################
# tree operations
#############################################################################
def find_re(n, target):
    if n is None:
        return None
    if n.value == target.value:
        return n
    found = None
    for c in n.children:
        found = find_re(c, target)
        if found:
            return found
    return None


def find(self, root, target):
    if root.value == target.value:
        return root
    return find_re(root, target)


#############################################################################
# test
#############################################################################
root = Node('a')
root.addOne(Node('b0'))
root.addMany([Node('b1'), Node('b2'), Node('b3'),])

print(root)
