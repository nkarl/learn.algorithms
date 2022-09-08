# template for DFS
from collections import defaultdict, deque


def bfs_core(graph, queue: deque, visited):
    """
        - Marks v as visited.
        - Visits and marks all unvisited adjacents of v.
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
        Finds a path from v.
    """
    visited = set()
    queue = deque([v])
    bfs_core(graph, queue, visited)
    pass


def add_edge(graph, u, v):
    """
        Adds an edge for u and v.
    """
    graph[u].append(v)
    pass


# creates empty graph
g1 = defaultdict(list)

# init the graph with vertices
add_edge(g1, 0, 1)
add_edge(g1, 0, 2)
add_edge(g1, 1, 0)
add_edge(g1, 1, 3)
add_edge(g1, 1, 4)
add_edge(g1, 2, 0)
add_edge(g1, 3, 1)
add_edge(g1, 4, 2)
add_edge(g1, 4, 3)


print("Graph:")
for k, v in g1.items():
    print(f"\tnode: {k}, adj: {v}")

# run dfs on the graph
print("Path from 2:", end='\n\t')
bfs(g1, 2)
