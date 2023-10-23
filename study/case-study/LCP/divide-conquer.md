## Problem: 

### We have a problem statement

- Given:
	- some collection of strings of varying lengths.
	- the collection is in the form of an array.

- Do:
	- Find the Longest Common Prefix (LCP) of these strings.

### We first observe that

We notice that the array is a collection. This means that it can be broken down into sub-problems.
### Our hypothesis is that

The smallest sub-problem is a group of two strings, in which case we compare them directly *to find the shorter string* out of the two. We replicate this process for the remaining sub-problems. Eventually, we will arrive at the shortest string in the entire collection.

### We induce our reasoning as follows

- If there is *only one string* in the array, then it is the solution because it is the shortest string by itself (a singleton).
- If there are *two strings* in the array (collection of size 2), then we *compare the two strings* and *find the shorter* of the two.
- If there are *more than two* strings in the array, we do as follows. We select any two strings, compare them and find the shorter of the two. This is our sub-problem. We repeat this process for all base pairs in the array. Next, we combine the solutions of our sub-problems as pair and make them sub-problems again. We recur until there is only one string left. This is the final solution.
	- *Now*, we must find a strategy for grouping any two strings as apair.

### Finally, we implement the algorithm in a language of choice

```python

def divide_conquer(array: [str], s1: int, s2: int) -> str:
	
	pass

def LCP(array: [str]) -> str:
	if len(array) == 1:
		return array[0]
	return divide_conquer(array)

```

### Final thoughts
