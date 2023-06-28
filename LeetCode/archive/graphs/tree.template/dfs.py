# Tree Structure: graph, directed
class TreeNode:
    children = []
    seem = False
    pass


def process(node: TreeNode):
    """process the node data."""
    return node


# Iterative DFS
def dfs(root: TreeNode):
    if root is None:
        return

    stack = [root]  # add root to stack
    visited = [root]  # add root to visited 

    while len(stack) > 0:
        top = stack.pop(-1)
        process(top)

        if top not in visited:
            visited += [top]
            for node in top.children:
                stack += [node]
    pass


# Recursive DFS, NOTE: INTUITIVE
def dfs_recursive(node: TreeNode, visited: list[TreeNode]):
    if node is None:
        return

    visited += [node]  # add root to visited
    for c in node.children:
        if c not in visited:
            dfs_recursive(c, visited)
    pass
