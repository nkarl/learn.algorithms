# Tree Structure: graph, directed
class TreeNode:
    children = set()
    seem = False
    pass


def process(node: TreeNode):
    """process the node data."""
    return node


# DFS: Checks if a vertex has been explored AFTER popping it from stack
# Iterative DFS, VERBOSE
def dfs(root: TreeNode):
    if root is None:
        return

    stack = [root]  # add root to stack
    explored = set()  # add root to explored

    while len(stack) > 0:
        top = stack.pop(-1)
        # additional condition to process here
        #   if top match some condition -> break while
        if top not in explored:
            explored.add(top)
            for child in top.children:
                stack += [child]
    pass


# Recursive DFS, NOTE: INTUITIVE
def dfs_recursive(n: TreeNode, explored: set):
    # if top match some condition -> break recurrence
    if n is None:
        return

    # additional condition to process here
    explored.add(n)  # add root to explored
    for c in n.children:
        if c not in explored:
            dfs_recursive(c, explored)
    pass
