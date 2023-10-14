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
# A stack grows very fast if each node has many children (more fanned out).
def dfs(root: TreeNode):
    if root is None:
        return

    stack = [root]  # add root to stack
    explored = set()  # add root to explored

    while len(stack) > 0:
        top = stack.pop(-1)
        # additional condition to process here
        #   if top matches some condition -> break while
        if top not in explored:
            explored.add(top)

            for child in top.children:
                stack += [child]
    pass


# Recursive DFS, NOTE: INTUITIVE
def dfs_recursive(n: TreeNode, condition: bool):
    # if top match some condition -> break recurrence
    if n is None:
        return

    # additional condition to process here
    # explored.add(n)  # add root to explored
    matched: bool = eval_condition(condition)
    for c in n.children:
        if condition is not matched:
            dfs_recursive(c, condition)
    pass


def eval_condition(condition: bool) -> bool:
    return condition
