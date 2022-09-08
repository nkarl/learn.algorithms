# template for BFS
from collections import defaultdict, deque
import graphutils


def bfs_core(graph, queue: deque, visited):
    """
        - Marks v as visited.
        - Queues up all unvisited adjacents of v.
    """
    if queue.count == 0:
        return

    v = queue.popleft()
    visited.add(v)
    print(v, end=' ')
    for u in graph[v]:
        if u not in visited:
            queue.append(u)
            bfs_core(graph, queue, visited)
    pass


def bfs(graph, v):
    """
        Finds all paths from v, expanding laterally.
    """
    visited = set()
    queue = deque([v])
    bfs_core(graph, queue, visited)
    pass


# creates empty graph
g1 = defaultdict(list)

# init the graph with vertices
graphutils.add_edge(g1, 0, 1)
graphutils.add_edge(g1, 0, 2)
graphutils.add_edge(g1, 1, 0)
graphutils.add_edge(g1, 1, 3)
graphutils.add_edge(g1, 1, 4)
graphutils.add_edge(g1, 2, 0)
graphutils.add_edge(g1, 3, 1)
graphutils.add_edge(g1, 4, 2)
graphutils.add_edge(g1, 4, 3)


print("Graph:")
for k, v in g1.items():
    print(f"\tnode: {k}, adj: {v}")

# run dfs on the graph
print("Path from 2:", end='\n\t')
bfs(g1, 2)
