#include <iostream>

// x^y without modulus, recursive.
// Overflows long long quickly (e.g. 2^63), so it's only for small results.
long long binpow(long long a, long long n){
	if (n == 0)
		return 1;
	if (n % 2 == 0){
		long long temp = binpow(a, n / 2);
		return temp * temp;
	}
	else
		return a * binpow(a, n - 1);
}

// x^y mod n, iterative: walk over the bits of y from the lowest one.
long long pow_mod_loop(long long x, long long y, long long n){
    long long res = 1 % n; // 1 % n handles n == 1 (anything mod 1 is 0)
    x %= n;
    // while y != 0
    while (y){
        // if the smallest bit is 1 then number is odd
        if (y & 0x01)
            res = (res * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return res;
}

// x^y mod n, recursive: the same idea, `res` carries the accumulated result.
long long pow_mod_recursive_step(long long x, long long y, long long n, long long res){
    if (y == 0)
        return res;
    // if the smallest bit is 1, if so, then number is odd
    else if (y & 0x01)
        return pow_mod_recursive_step((x * x) % n, y >> 1, n, (res * x) % n);
    // if the smallest bit is 0, then number is even
    return pow_mod_recursive_step((x * x) % n, y >> 1, n, res);
}

long long pow_mod_recursive(long long x, long long y, long long n) {
    return pow_mod_recursive_step(x % n, y, n, 1 % n);
}

int main(){
    long long x, y, n;
    std::cin >> x >> y >> n;
    if (y < 0 || n <= 0){
        std::cout << "y must be >= 0 and n must be > 0" << std::endl;
        return 1;
    }
    std::cout << "x^y                   = " << binpow(x, y) << std::endl;
    std::cout << "x^y mod n (loop)      = " << pow_mod_loop(x, y, n) << std::endl;
    std::cout << "x^y mod n (recursive) = " << pow_mod_recursive(x, y, n) << std::endl;
}
