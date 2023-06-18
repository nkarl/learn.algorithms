class TreeNode:
    neighbors = []
    pass

def process(node: TreeNode):
    """process the node data."""
    pass

def dfs(root: TreeNode):
    if root is None:
        return

    s = []
    s += [root]     # add root to queue
    v = []
    v += [root]     # add root to visited

    while s is not None:
        curr, s = s[0], s[:-1]
        process(curr)

        for node in curr.neighbors:
            if node not in v:
                s += [node]
                v += [node]
    pass


def dfs_recursive(root: TreeNode, v: list[TreeNode]):
    if root is None:
        return

    v += [root]     # add root to visited

    for node in root.neighbors:
        if node not in v:
             dfs_recursive(node, v)
    pass
