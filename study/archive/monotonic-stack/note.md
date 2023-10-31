- **The problem**
	- I have been working on the monotonic stack pattern, and I am struggling to purify the information and abstract out a pure form of the pattern.
 - The observations
	 - not seen enough problem variety; so far has only seen one single problem
		 - problem \#0456, check if the 132 pattern exits in an array.

I understand the result and requirement. However, the order switching of $j$ and $k$ is a *source of entropy*, which has interfered with the purification process. So, let's decompose it and go through it piece-wise to understand it.

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
$$

$$
3 < 5 < 4
$$

First, we observe the requirements.

- $i$ is the lower-bound index. $k$ is the the upper-bound index.
- $s_i$ is the lower-bound value. $s_j$ is the upper-bound value.
- This means that **as long as we find $s_k$** we only need to find:
	- $s_j$ such that $s_j > s_k$, and
	- $s_i$ such that $s_i < s_k$.

For the solution, we just need to <u>find the first instance</u> where <u>the condition is met</u>. We don't care about if other solution sets exist. If we use a monotonic stack, condition (1) is automatically checked, which simplifies our solution. We only need to check for (2).

Now, **why** do we use a monotonic stack?

First, we need to understand the <u>nature</u> of a monotonic stack. A monotonic stack is simply *a sorted stack*. Next, we need to figure out in which way that we want to keep it sorted. *Non-increasing* or *non-decreasing* or a strict version of either cases?

For every element $n$ counting from the end of the array, we push it on the stack. Before we push, we check the stack.

- If the stack:
	- is not empty, and
	- its top $< n$, then
- we <u>keep popping</u> until this is no longer true
	- In other words, we **maintain the stack to be non-decreasing according to** $\textbf{n}$. <span style='background-color:yellow'>This is our monotonicity</span>.
 
Then, we have our first set of candidates:

1. candidate pair:
	- *the last popped top* is our candidate for $s_k$
	- we push $n$ to stack, and *as the current top of the stack*, this round's $n$ is our candidate for $s_j$
	- where $s_k \leq s_j$
```python
for n in nums[::-1]:
	while stack and stack[-1] < n: # we keep the stack sorted in a non-increasing manner
		sk = stack.pop()
	stack.append(n)
```

2. In the following rounds of iteration, we just need to find $s_i$.
	1. if $n < s_k$ we return immediately, because $n$ is our $s_i$.
	2. otherwise, we continue until we exhaust all iterations. Then, we conclude that no such triplet exists.
```python
for n in nums[::-1]:
	if n < sk: # we check for candidate si here
		return True
	while stack and stack[-1] < n: # we keep the stack sorted in a non-increasing manner
		sk = stack.pop()
	stack.append(n)
return False
```
