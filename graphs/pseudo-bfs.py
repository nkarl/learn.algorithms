class TreeNode:
    pass

def process(node: TreeNode):
    """process the node data."""
    pass

def bfs(root: TreeNode):
    if root is None:
        return

    q = []
    q += [root]     # add root to queue
    v = []
    v += [root]     # add root to visited

    while q is not None:
        curr = q.pop()
        process(curr)

        for node in curr.neighbors:
            if node not in v:
                q += [node]
                v += [node]
    pass
