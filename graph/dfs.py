# template for DFS
from collections import defaultdict

def add_edge(graph, u, v):
    graph[u].append(v)
    pass


def dfs_core(graph, vertex, visited):
    visited.add(vertex)
    print(vertex, end=' ')
    for v in graph[vertex]:
        if v not in visited:
            dfs_core(graph, v, visited)
    pass

def dfs(graph, vertex):
    visited = set()
    dfs_core(graph, vertex, visited)
    pass


if __name__ == "__main__":
    # creates empty graph
    g1 = defaultdict(list)

    # init the graph with vertices
    add_edge(g1, 0, 1)
    add_edge(g1, 0, 2)
    add_edge(g1, 1, 2)
    add_edge(g1, 2, 0)
    add_edge(g1, 2, 3)
    add_edge(g1, 3, 3)

    # run dfs on the graph
    dfs(g1, 2)
