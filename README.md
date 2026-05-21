# Data Structures and Algorithms in C

A collection of standalone C programs implementing classical algorithms, data structures, and Monte Carlo numerical experiments, written during introductory algorithms coursework.

## Contents

| File | What it does |
|---|---|
| `Aho-Corasick Algorithm .c` | Multi-pattern string matching via the Aho–Corasick automaton (trie + failure links). |
| `BST.c` | Binary search tree implementation with insertion, search, and traversal. |
| `estimating e using uniform distributions.c` | Monte Carlo estimate of Euler's number `e` by drawing uniforms until the running sum exceeds 1. |
| `estimating pie using 2d random distribution.c` | Monte Carlo estimate of π by sampling points inside a unit square and counting hits inside the inscribed circle. |
| `array division.c` | Splitting an array into segments under a balance constraint. |
| `building a number by adding 3 numbers from a list.c` | 3-sum-style combinatorial search problem. |
| `max area using sticks.c` | Maximum rectangular area selection from a set of sticks. |
| `mission management.c` | Scheduling/assignment problem implementation. |
| `weird calculation.c` | A bespoke arithmetic puzzle from the coursework. |

## How to Build and Run

Each file is self-contained. Compile with any standard C compiler:

```bash
gcc -O2 -Wall "Aho-Corasick Algorithm .c" -o aho_corasick
./aho_corasick
```

## License

MIT — see [LICENSE](LICENSE).
