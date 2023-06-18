- Given:
  - a tree $T$ (not necessarily binary), and
  - some node $n_i$ within the tree

- Do:
  - delete the node $n_i$ and send all of its children to its parent.
    -  In other words, the orphan children will be sent to the grandparent.

At a glance we have three scopes to be mindful of: the grandparent, the parent and the children.

At the grandparent scope, we need to check if there exists one node among the children (of the grandparent) that matches the given node $n_i$. Immediately, we can see that we need a loop here, because we need to check each item in a collection.

Now, two cases might happen for each iteration. Either the node matches or it doesn't.

If it is a match, we can immediate move to the next operation: reap its children and send to the grandparent (we are still in the grandparent scope).

If it is not a match, we have to recur on the unmatched child itself.