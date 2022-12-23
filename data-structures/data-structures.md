# Data Dtructures

### Disjoint Set Union

The basic interface of this data structure consists of three operations:

`init(n)` - initializes n separate sets, each containing one element

`merge(u, v)` - merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)

`find(v)` - returns the representative (also called leader) of the set that contains the element v.

### Fenwick Tree

Fenwick tree is a data structure which implements such methods:

`f(l, r)` - calculates the value of function `f`  in the given range  `[l, r]`

`delta(i, d)` - updates the value of an `i`-th element
