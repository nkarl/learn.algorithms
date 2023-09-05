# template for DFS
from collections import defaultdict
import graphutils
import sys


def dfs_core(graph, v, visited):
    """
        - Marks v as visited.
        - Recurs for each unvisited adjacents of v.
    """
    if len(visited) == len(graph):
        return
    #
    visited.add(v)
    print(v, end=' ')
    for w in graph[v]:
        if w not in visited:
            #
            dfs_core(graph, w, visited)
    pass


def dfs(graph, v):
    """
        Finds all paths from v, deepest first.
    """
    visited: set = set()
    #
    dfs_core(graph, v, visited)
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

# run dfs on the graph
start = int(sys.argv[1])
print(f"Path from {start}:", end='\n\t')
dfs(g1, start)
