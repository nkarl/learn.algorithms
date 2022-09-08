# template for DFS
from collections import defaultdict
import graphutils


def dfs_core(graph, v, visited):
    """
        - Marks v as visited.
        - Recurs for each unvisited adjacents of v.
    """
    #
    #

    #
    visited.add(v)
    print(v, end=' ')
    for u in graph[v]:
        if u not in visited:
            #
            dfs_core(graph, u, visited)
    pass


def dfs(graph, v):
    """
        Finds all paths from v, deepest first.
    """
    visited = set()
    #
    dfs_core(graph, v, visited)
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
dfs(g1, 2)
