#!/usr/bin/env bash
# Runs every program on a small input and compares the output.
# Whitespace differences (spaces vs new lines) are ignored.
cd "$(dirname "$0")/.." || exit 1
pass=0
fail=0

# check <binary> <stdin> <expected stdout>
check() {
    local bin="build/$1" input="$2" expected="$3" actual
    actual=$(printf "%b" "$input" | timeout 5 "$bin" 2>&1)
    if [ "$(echo $actual)" == "$(echo $expected)" ]; then
        pass=$((pass + 1))
    else
        fail=$((fail + 1))
        echo "FAIL $1 (input: $input)"
        echo "  expected: $(echo $expected)"
        echo "  actual:   $(echo $actual)"
    fi
}

# sorting: random-looking input with negatives and duplicates, plus empty input
for s in bubble_sort gnome_sort insertion_sort merge_sort quick_sort gapped_exchange_sort; do
    check "sorting/$s" "8  5 -2 9 0 -2 7 3 1" "-2 -2 0 1 3 5 7 9"
    check "sorting/$s" "5  -2 -5 3 4 -3"      "-5 -3 -2 3 4"
    check "sorting/$s" "0"                    ""
    check "sorting/$s" "1  42"                "42"
done

check searching/binary_search "5  1 3 5 7 9  7" "3"
check searching/binary_search "5  1 3 5 7 9  4" "-1"
check searching/binary_search "0  4"            "-1"

check graphs/bfs "3 0 2\n0 1 0\n1 0 1\n0 1 0" "2"
check graphs/bfs "3 0 2\n0 0 0\n0 0 0\n0 0 0" "-1"
check graphs/dfs "3 1 3\n0 1 0\n1 0 1\n0 1 0" "Yes"
check graphs/dfs "3 1 3\n0 1 0\n1 0 0\n0 0 0" "No"
check graphs/dijkstra "3 0 4\n0 1 1\n1 2 1\n2 0 1\n0 2 1" "0 0 = 0 0 1 = 1 0 2 = 1"
check graphs/dijkstra "3 0 3\n0 1 4\n0 2 1\n2 1 2"       "0 0 = 0 0 1 = 3 0 2 = 1"
check graphs/dijkstra "3 0 1\n0 1 5"                     "0 0 = 0 0 1 = 5 0 2 = unreachable"
check graphs/a_star "" "We found the path between start and end points! The path: -> (8;0) -> (7;0) -> (6;0) -> (5;0) -> (4;1) -> (3;2) -> (2;1) -> (1;0) -> (0;0)"
check graphs/lee "" "The length of the path is 3"

check data_structures/stack "push 1\npush 2\npop\ncount\nempty\npop\nis_empty\n-1" "2 1 -1 1"
check data_structures/queue "push 1\npush 2\npop\nsize\npop\npush 3\ncount\n0"   "1 1 2 3"
check data_structures/deque "push_back 1\npop_back\npush_back 2\npush_front 3\ncount\npop_front\nfront\nback\nsize\n0" "1 2 3 3 2 2 1"
check data_structures/binary_search_tree "" "inorder: 1 3 4 5 7 8 9 preorder: 5 3 1 4 8 7 9 postorder: 1 4 3 7 9 8 5 search 4: found search 6: not found"
check data_structures/hash_table "" "Key was inserted Key was inserted Key was inserted Key was inserted Key exists, values was replaced Value for key: 10005 was found: one Item for: 1005 was not found Item with key: 0 was erased Item for: 0 was not found Key: 2 and Value: two again Key: 10005 and Value: one Key: -5 and Value: minus five"

check math/gcd "12 18" "6"
check math/gcd "-4 -6" "2"
check math/fast_power "3 13 7"   "x^y = 1594323 x^y mod n (loop) = 3 x^y mod n (recursive) = 3"
check math/fast_power "2 0 1"    "x^y = 1 x^y mod n (loop) = 0 x^y mod n (recursive) = 0"
check math/sieve_of_eratosthenes "30" "2 3 5 7 11 13 17 19 23 29"
check math/sieve_of_eratosthenes "7"  "2 3 5 7"
check math/primes_in_sequence "2 4 -5 7 1 9 11 0" "2 7 11"
check math/factorization "360"        "2 2 2 3 3 5"
check math/factorization "1000000007" "1000000007"
check math/fibonacci "10" "2 3 5 8 13 21 34 55 89 144"
check math/matrix_inverse_gauss "2 2  4 7  2 6" "Input matrix size (n x n): 0.6 -0.7 -0.2 0.4"
check math/matrix_inverse_gauss "2 2  0 1  1 0" "Input matrix size (n x n): 0 1 1 0"
check math/matrix_inverse_gauss "2 2  1 2  2 4" "Input matrix size (n x n): Not possible to calculate invertible matrix"

# RSA keys are random, so only check that decryption restores the message
rsa_out=$(echo "123456" | timeout 5 build/cryptography/rsa)
if echo "$rsa_out" | grep -qx "decrypted text: 123456"; then
    pass=$((pass + 1))
else
    fail=$((fail + 1)); echo "FAIL cryptography/rsa"; echo "$rsa_out"
fi

check knapsack/knapsack_01_dp "" "220"
check knapsack/knapsack_fractional_greedy "" "240"

echo "passed: $pass, failed: $fail"
[ "$fail" -eq 0 ]
