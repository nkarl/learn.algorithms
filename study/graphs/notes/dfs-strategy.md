## Problem 1: Delete a node and send its children to its parent

- Given:
  - a tree $T$ (*not necessarily binary*), and
  - some node id `id`

- Do:
  - delete the node $n_i$ whose id matches `id` and send all of its children to its parent.
    -  In other words, the orphan children will be sent to the grandparent.

At a glance, we see that we have two scopes to work with: the parent and the child. We never need to enter the scopes of the grandchildren; we only need their references/ids in order to relocate them to their new parent/guardian.

Now we describe the operation in detail.

For each node $n_i$ in the tree $T$, <u>there exists one node among its children whose id matches that of the given node</u> $n_i$. Because a tree may have many layers (generations of descendants), we recognize that a recurrence/iteration must exist as long as the break condition is not met.

Now, two cases might happen for each recurrence/iteration. Either the node matches or it doesn't.

- Matched: we immediate break the recurrence/iteration and <u>move to the next operation</u>:
    - return the child's id (from which we can get its children) to the parent's scope, and
    - iterate and bind each of its chidren to the new parent.
- Matched **NOT**: we recur *depth-first* through the tree.

