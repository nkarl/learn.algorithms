def add_edge(graph: dict, u, v):
    """
        Adds an edge for u and v.
    """
    graph[u].append(v)
    pass

def makegraph(graph: dict, ps: list):
    """
        Make a graph from a list of points.
    """
    for u, v in ps:
        add_edge(graph, u, v)
    pass
