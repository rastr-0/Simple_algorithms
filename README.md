# Simple algorithms

A collection of classic algorithms and data structures I wrote in C++ while
learning programming at school. Every file is a small standalone program.
The comment at the top of each file explains the idea, the complexity and the
input format, with an example.

## Build and run

Needs a C++17 compiler (g++ or clang++) and `make`.

```sh
make                 # builds everything into build/<category>/<name>
make test            # builds and runs tests/run_tests.sh
make clean

echo "5  3 1 4 1 5" | ./build/sorting/quick_sort
```

To check for memory errors and undefined behaviour:

```sh
make clean && make test CXXFLAGS="-std=c++17 -g -fsanitize=address,undefined"
```

## Contents

### Sorting

| Algorithm | Idea | Time | Memory |
|---|---|---|---|
| [Bubble sort](sorting/bubble_sort.cpp) | swap neighbours in the wrong order, pass after pass | O(n²) | O(1) |
| [Gnome sort](sorting/gnome_sort.cpp) | step back while the previous element is bigger | O(n²) | O(1) |
| [Insertion sort](sorting/insertion_sort.cpp) | insert each element into the sorted prefix | O(n²) | O(1) |
| [Gapped exchange sort](sorting/gapped_exchange_sort.cpp) | compare-and-swap elements `h` apart, halving `h` (Shell-sort-like) | O(n²) | O(1) |
| [Merge sort](sorting/merge_sort.cpp) | sort both halves, merge them | O(n log n) | O(n) |
| [Quick sort](sorting/quick_sort.cpp) | partition around a pivot, recurse | O(n log n) avg, O(n²) worst | O(log n) |

### Searching

| Algorithm | Idea | Time | Memory |
|---|---|---|---|
| [Binary search](searching/binary_search.cpp) | halve the sorted range each step | O(log n) | O(log n) |

### Graphs

| Algorithm | Idea | Time |
|---|---|---|
| [BFS](graphs/bfs.cpp) | level-by-level search, fewest edges between two vertices | O(V²) (adjacency matrix) |
| [DFS](graphs/dfs.cpp) | go deep first, answers "is F reachable from S?" | O(V²) (adjacency matrix) |
| [Dijkstra](graphs/dijkstra.cpp) | shortest paths from one vertex, non-negative weights | O(V² + V·E) |
| [A*](graphs/a_star.cpp) | shortest path on a grid, guided by a heuristic, 8 directions | O(RC log RC) |
| [Lee algorithm](graphs/lee.cpp) | wave (BFS) on a grid, 4 directions | O(RC) |

### Data structures

| Structure | Built on | Operations |
|---|---|---|
| [Stack](data_structures/stack.cpp) | singly linked list | push / pop in O(1) |
| [Queue](data_structures/queue.cpp) | singly linked list | push / pop in O(1) |
| [Deque](data_structures/deque.cpp) | doubly linked list | push / pop on both ends in O(1) |
| [Binary search tree](data_structures/binary_search_tree.cpp) | linked nodes | insert / search in O(height), in/pre/postorder traversal |
| [Hash table](data_structures/hash_table.cpp) | array of lists (separate chaining) | insert / search / remove in O(1) average |

### Math

| Algorithm | Idea | Time |
|---|---|---|
| [GCD](math/gcd.cpp) | Euclidean algorithm, gcd(a, b) = gcd(b, a mod b) | O(log min(a, b)) |
| [Fast power](math/fast_power.cpp) | x^y and x^y mod n by repeated squaring (loop + recursive) | O(log y) |
| [Sieve of Eratosthenes](math/sieve_of_eratosthenes.cpp) | all primes up to n | O(n log log n) |
| [Primes in a sequence](math/primes_in_sequence.cpp) | trial division of each number | O(√x) per number |
| [Prime factorization](math/factorization.cpp) | trial division | O(√n) |
| [Fibonacci numbers](math/fibonacci.cpp) | iterative | O(n) |
| [Matrix inverse](math/matrix_inverse_gauss.cpp) | Gauss-Jordan elimination with partial pivoting | O(n³) |

### Cryptography

| Algorithm | Idea |
|---|---|
| [RSA](cryptography/rsa.cpp) | toy RSA with small primes: key generation, encryption and decryption |

### Knapsack problem

| Variant | Approach | Time |
|---|---|---|
| [0/1 knapsack](knapsack/knapsack_01_dp.cpp) | items are taken whole or not at all, dynamic programming (tabulation) | O(n·W) |
| [Fractional knapsack](knapsack/knapsack_fractional_greedy.cpp) | items can be cut, greedy by value/weight ratio | O(n log n) |

## Known limitations

These are learning implementations, not production code:

- Numbers are plain `long` / `long long`, so big inputs overflow (Fibonacci after ~90 terms, `fast_power` for big results, RSA only works with small primes).
- Most programs assume well-formed input.
- The A*, Lee, binary search tree, hash table and knapsack demos use data hard-coded in `main()`.
