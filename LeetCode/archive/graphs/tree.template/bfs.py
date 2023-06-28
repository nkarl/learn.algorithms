# Tree Structure: graph, directed
class TreeNode:
    children = []
    seen = False
    pass


def process(node: TreeNode):
    """process the node data."""
    return node


# Iterative BFS, NOTE: INTUITIVE
def bfs(root: TreeNode):
    if root is None:
        return

    queue = [root]  # add root to queue
    visited = [root]  # add root to visited

    while len(queue) > 0:
        front = queue.pop(0)
        process(front)

        for node in front.children:
            if node not in visited:
                visited += [node]
                queue += [node]
    pass


# Recursive BFS: WIP; HIGHLY WRONG!
def bfs_recursive(node: TreeNode, visited: list[TreeNode]):
    if node is [None]:
        return

    if node not in visited:
        visited += [node]
        for c in node.children:
            bfs_recursive(c, visited)
    pass
