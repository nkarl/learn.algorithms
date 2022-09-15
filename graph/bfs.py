# template for BFS
from collections import defaultdict, deque
import graphutils
import sys


def bfs_core(graph, queue: deque, visited):
    """
        - Marks v as visited.
        - Queues up and recurs for each unvisited adjacents of v.
    """
    v = queue.popleft()
    visited.add(v)
    print(v, end=' ')
    if queue.count == 0:
        return
    for w in graph[v]:
        if w not in visited:
            queue.append(w)
            bfs_core(graph, queue, visited)
    pass


def bfs(graph, v):
    """
        Finds all paths from v, expanding laterally.
    """
    visited: set = set()
    queue: deque = deque([v])
    bfs_core(graph, queue, visited)
    pass


# creates empty graph
g1: defaultdict = defaultdict(list)

# init the graph with vertices
ps = [
    [0,1], [0,2], [1,0], [1,3], [1,4], [2,0], [3,1], [4,2], [4,3]
]
graphutils.makegraph(g1, ps)


print("Graph:")
for k, v in g1.items():
    print(f"\tnode: {k}, adj: {v}")

# run bfs on the graph
start = int(sys.argv[1])
print(f"Path from {start}:", end='\n\t')
bfs(g1, start)
