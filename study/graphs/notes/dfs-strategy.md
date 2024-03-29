## Problem 1: Delete a node and send its children to its parent

### We have a problem statement

- Given:
	- an *n-ary* tree $T$, and
	- some node id `id`

- Do:
	- delete some node whose id matches `id` and send all of its children to its parent.

### We first observe that

We never need to enter the scopes of the orphaned descendants $[c_1..c_n]$. In order to relocate them to their new guardian (namely $n_d$), we only need their id's, which can be retrieved from the former guardian $n_{d+1}$.

Thus, we have two lexical scopes to work with: the scope of some parent node $n_d$ and that of its child $n_{d+1}$. Our goal is to delete $n_{d+1}$ and sends its children to the new guardian $n_d$.

```mermaid
flowchart LR

subgraph old[" "]
    op1[<em>n<sub>d</sub></em>] -.- oc1[<em>n<sub>d+1</sub></em>]
    subgraph oorphan[" "]
        oc11
        oc12
        oc13
    end
    oc1 --- oc11[c1]
    oc1 --- oc12[c2]
    oc1 --- oc13[c3]
end

subgraph new[" "]
    np1[<em>n<sub>d</sub></em>] -.-|reaped by GC| ncd[<em>n<sub>d+1</sub></em>]
    subgraph norphan[" "]
        nc1
        nc2
        nc3
    end
    np1 --- nc1[c1]
    np1 --- nc2[c2]
    np1 --- nc3[c3]
end

old -.->|<p style='padding:1em'>after deletion</p>| new
```

### Our hypothesis is that

> In the tree $T$ there exists some node $n_d$, and among its children there exists some node $n_{d+1}$ whose id matches `id`.

### We induce our reasoning as follows

First, we assume that $n_{d+1}$ has matching id with `id`.

Because a tree might have many layers of depth (many generations of descendants), we recognize that a recurrence must exist for such a tree. This recurrence holds as long as the break condition is not met.

- Now, two cases might happen for each recurrence. Either the node matches `id` or it doesn't.
	- Matched: we immediately break the recurrence and <u>proceed to achieving the goal</u>:
		- return the child's id to the parent's scope, and then
		- collect and bind its children to the new parent.
	- Matched **NOT**: we *recur depth-first* through the remainder of the tree until hitting the leaf nodes.

### Finally, we implement the algorithm in a language of choice

```python
# class Node
class Node:
	children = []
	def Node(self)
		pass
	def remove(self, node)
		pass
	def insert(self, node)
		pass
	def insert(self, nodes)
		pass

# recursive
def deleteRecur(node, id):
    if not node.children:
        return
    for n in node.children:
        if n.id == id:
            node.remove(n)
            node.insert(n.children)
            return
        deleteRecur(n, id)

# delete interface
def delete(root, id):
    if root is None or root.children is None:
        return
    if root.id == id:
        return
    deleteRecur(root, id)
```

### Final thoughts

It is useful to notice that the delete operation is a side effect of the recurrence of id matching.

#### Notes on a tree and a graph

A tree is a constrained graph. It is important to keep in mind that this constraint makes all the difference. Because of the constraint, with a tree <u>we don't need keep an explicit set/list of explored nodes</u>. This is because of the nature of the tree where the leaf nodes are definite ends, i.e. a leaf node is a break condiion and it will never be visited again.

For a graph, nodes might be cyclic. This means additional complexity we have to handle. A node might point to a series of nodes which might end up pointing at itself, i.e. a cycle. This is <u>why we need a set of explored nodes</u>, to keep track of which nodes have been visited.
