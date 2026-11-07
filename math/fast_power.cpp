#include <iostream>

long pow_mod(long x, long y, long n){
    long res = 1;
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

int main(){
    long x, y, n;
    std::cin >> x >> y >> n;
    std::cout << pow_mod(x, y, n);
}
