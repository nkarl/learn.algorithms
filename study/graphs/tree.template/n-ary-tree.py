class Node:
    value = None
    children = []

    def Node(self, value):
        self.value = value


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


root = None


def find(self, target):
    if root.value == target.value:
        return root
    return find_re(root, target)


root = Node(0)
