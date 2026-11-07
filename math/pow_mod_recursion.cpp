#include <iostream>

long f(long x, long y, long n, long res){
    if (y == 0)
        return res;
    // if the smallest bit is 1, if so, then number is odd
    else if (y & 0x01)
        return f((x * x) % n, y >> 1, n, (res * x) % n);
    // if the smallest bit is 0, then number is even
    return f((x * x) % n, y >> 1, n, res);
}

long pow_mod(long x, long y, long n) {
    return f(x, y, n, 1);
}
 
int main() {
    long x, y, n;
    std::cin >> x >> y >> n;
    std::cout << pow_mod(x, y, n);
}