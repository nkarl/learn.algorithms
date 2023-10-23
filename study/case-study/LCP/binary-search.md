## Problem: Find the Longest Common Prefix from an array of strings

### We have a problem statement

- Given:
	- some collection of strings of varying lengths.
	- the collection is in the form of an array.

- Do:
	- Find the Longest Common Prefix (LCP) of these strings.

### We first observe that

We notice that the array is a collection. We need to find a common point of all elements in this collection. We observe that this is a recurrent activity. This means that it can be broken down into sub-problems.

We also observe that, given the varying lengths of the collection, there must be a string $s$ that is the shortest in length. Any LCP, if exists, must be a prefix of this string $s$. We already have information about this string, both its start and end indices. We can search for an index in this range such that it is the end of our LCP.

### Our hypothesis is that

For every index within the length of the starting shortest string, there exists one that terminates the actual LCP.

### We induce our reasoning as follows

- If there is *only one string* in the array, then it is the solution because it is the shortest string by itself (a singleton).
- If there are *two strings* in the array (collection of size 2), then we *compare the two strings* and *find the shorter* of the two.
- If there are *more than two* strings in the array, we do as follows. We select any two strings, compare them and find the shorter of the two. This is our sub-problem. We repeat this process for all base pairs in the array. Next, we combine the solutions of our sub-problems as pair and make them sub-problems again. We recur until there is only one string left. This is the final solution.

### Finally, we implement the algorithm in a language of choice

```python
# find the LCP of two strings; checks every character in the two strings, return only the LCP
def findLCP(s1: str, s2: str):
	shorter = min(len(s1), len(s2))
	for i in range(len(shorter)):
		if s1[i] != s2[i]:
			return s1[:i]
	return s1[:shorter]

# divide and conquer the subproblems
def divide_conquer(array: [str], lo: int, hi: int) -> str:
	if lo == hi:
		return array[lo]
	mid = lo + (hi - lo) / 2
	a = divide_conquer(array, lo     , mid)
	b = divide_conquer(array, mid + 1, hi )
	return findLCP(a, b)

# entry point
def LCP(array: [str]) -> str:
	if len(array) == 1:
		return array[0]
	return divide_conquer(array)

```

### Final thoughts

There are two possible ways to use the two-pointer technique, each dependent on the implementation of recurrence. For example, many for/while loops use the descending/ascending pointers. Another way the two pointers can move in a for/while loop is they start at opposite end and meet in the middle.

On the other hand, for a recursion, it is best to use the same form as a recursive binary search with low and high pointers.
