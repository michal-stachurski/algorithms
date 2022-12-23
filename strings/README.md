# String Processing

### String Hashing

Basic implementation of a polynomial rolling hash function. Handling substring hash queries (ex. [lexic_comp.cc](lexic_comp.cc)).

### Trie (Data Structure)

Trie is a rooted tree, where each edge of the tree is labeled by some letter. All outgoing edges from one node must have different labels. Used for storying words on it

`init()` - initializes empty tree (creating root node)

`add(string)` - adding `string` to tree

`delete(string)` - deleting `string` from tree (not implemented yet)

`test(string)` - checks if there is a `string` in the tree

First umplementation uses `std::string` ([trie.cc](trie.cc)), second basic `cstring` ([__trie.cc](__trie.cc)).


### Knuth–Morris–Pratt algorithm (KMP)

Calculating **prefix function** for string, which is defined as array `pi`, where `pi[i]` is the length of the longest proper prefix of the substring (of lenght `i`), which is also a suffix of this substring.


### KMR
### Z algorithm

The **Z-function** for given string is an array where the `i`-th element is equal to the greatest number of characters starting from the position `i` that coincide with the first characters of given string.



## TODO

### Suffix Array (Data Structure)
### Manacher's Algorithm
### Aho-Corasick Algorithm

## ???

### Suffix Tree (Data Structure)
### Suffix Automaton
### Lyndon factorization