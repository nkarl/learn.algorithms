## Problem: Find the Longest Common Prefix from an array of strings

### We have a problem statement

- Given:
	- some collection of strings of different lengths.
	- the collection is an array.

- Do:
	- Find the Longest Common Prefix (LCP) of these strings.

### We first observe that

We notice that the array is a collection. We need to find a <u><i>substring</i> that is the <b>common prefix</b></u> of all elements in this collection. We observe that this is a recurrent activity. This means that it can be broken down into sub-problems.

We also observe that, given the strings in the collection vary in length, *there must be some string $s$ that is the <b>shortest string</b> in the entire collection*. Any LCP, if exists, must be a prefix of this string $s$. We already have information about this string: the start index and end index. We can search for an index in this range such that it terminates the LCP.
	
### Our hypothesis is that

For every such collections of strings, there is one shortest string among them. Then, among the shortest string's characters, there exists one character that terminates the actual LCP.

### We induce our reasoning as follows

- If there is *only one string* in the array, then it is the solution because it is the shortest string by itself (a singleton).
- If there are *more than one string* in the array, then we check each string and find the minimum length. This is our entry point to the next step.
- We **do a binary search** with the *start index* and *end index* of the shortest string. The success condition for this binary check is that it has to be the LCP. Thus, this condition is abstracted into a separate function, in which we iterate and check that this index is true for all strings in the array.
	- *Now*, there are two cases for the target index: it is either **true** or **not**. This means we just need one single instance to be true.
		- `target == 0`: no prefix is found
		- `0 < target <= shortest`: some prefix exists

### Finally, we implement the algorithm in a language of choice

```python
# the check if the terminating index is true for all strings in the collection
def isLCP(array: [str], end: int) -> bool:
	for s in array:
		if s.find(array[0][:end]) != 0:
			return false
	return true

# the binary search algorithm for the terminating index
def binary_search(array: [str], lo: int, hi: int) -> str:
	if lo > hi:
		return array[0][:hi]
	mid = lo + (hi - lo) / 2
	if (isLCP(array, mid)) return binary_search(array, mid + 1, hi)
	else                   return binary_search(array, lo, mid - 1)

# the main function
def LCP(array: [str]) -> str:
	if len(array) == 1:
		return array[0]
	shortest = min(array, key=len)
	return binary_search(array, 0, shortest)

```

### Final thoughts

This approach puts **less stress on the memory stack** because only the index values are saved on the stack. The iteration to check for valid string is done as a loop, which is memory efficient, and can even be parallelized if needed.
