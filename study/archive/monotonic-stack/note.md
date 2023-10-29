I have been working on the monotonic stack pattern, and I am struggling to purify the information and reach a pure form of the pattern. I understand the result and requirement. However, the order switching of $j$ and $k$ is a *source of entropy*, which has interfered with the purification process:

$$
i < \boldsymbol{\color{red}{j}} < k \quad (1)
$$
$$
s_i < \boldsymbol{s_{\color{red}k}} < s_j \quad (2)
$$

| index   | i=0   | <span style='background-color:yellow'>j=1</span>   | 2   | 3   | k=4   |
| --- | --- | --- | --- | --- | --- |
|     | $s_i=$ 3   | $s_j=$ 5   | 0   | 3   | $s_k=$ <span style='background-color:yellow'>4</span>   |

$$
0 < 1< 4
$$ $$
3 < 5 < 4
$$
Now, **why** do we use a monotonic stack?

- First, we observe the solution.
	- $i$ is the lower-bound index. $k$ is the the upper-bound index.
	- $s_i$ is the lower-bound value. $s_j$ is the upper-bound value.
- This means that as long as we find $s_k$ we only need to find:
	- the $s_j$ that is larger than it, and
	- the $s_i$ that is smaller than it.

First, we need to understand the <u>nature</u> of a monotonic stack. A monotonic stack is either non-*de*creasing or non-*in*creasing. In other words, it is *a sorted stack*.

For the solution, we just need to find the first instance where the condition is met. We don't care about if other solution sets exist. If we use a monotonic stack, condition (1) is automatically checked, which simplifies our solution. We only need to check for (2).

For every element $n$ counting from the end of the array, we push it on the stack. Before we push, we check the stack. If it is not empty, and the top of the stack is less than the element $n$, we <u>keep popping</u> until this is not true. Then, we have our first set of candidates:

1. candidate pair:
	- *the top of the stack* is our candidate for $s_k$
	- *this round's* $n$ is our candidate for $s_j$
	- where $s_k \leq s_j$
```python
for n in nums[::-1]:
	while stack and stack[-1] < n: # we keep the stack sorted in a non-increasing manner
		sk = stack.pop()
	stack.append(n)
```

2. In the following rounds of iteration, we just need to find $s_i$.
	1. if $n < s_k$ we return immediately, because $n$ is our $s_i$.
	2. otherwise, we continue until we exhaust the iteration. Then, we conclude that no such triplet exist.
```python
for n in nums[::-1]:
	if n < sk: # we check for candidate si here
		return True
	while stack and stack[-1] < n: # we keep the stack sorted in a non-increasing manner
		sk = stack.pop()
	stack.append(n)
return False
```
