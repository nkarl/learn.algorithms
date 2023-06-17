class TreeNode:
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
