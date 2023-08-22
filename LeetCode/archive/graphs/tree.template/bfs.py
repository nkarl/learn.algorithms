# Tree Structure: graph, directed
class TreeNode:
    children = []
    seen = False
    pass


def process(node: TreeNode):
    """process the node data."""
    return node


# BFS: Check if a vertex has been explored BEFORE queuing it
# Iterative BFS, NOTE: INTUITIVE
def bfs(root: TreeNode):
    if root is None:
        return

    queue = [root]  # add root to queue
    explored = set()  # add root to explored 

    while len(queue) > 0:
        front = queue.pop(0)
        # additional condition to process here
        #   if top match some condition -> break while
        for child in front.children:
            if child not in explored:
                explored.add(child)
                queue += [child]
    pass


# Recursive BFS: WIP; HIGHLY LIKELY WRONG!
# NOTE: recursive BFS seems to employ a post-order traversal
def bfs_recursive(n: TreeNode, explored: set):
    if n is None:
        return


    for c in n.children:
        bfs_recursive(c, explored)
        if n not in explored:
            explored.add(n)  # add root to explored
    pass
