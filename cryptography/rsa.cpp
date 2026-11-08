/*
 * RSA (toy version)
 *
 * Generates two random primes p, q (1000..11000), builds the public key
 * (e, n) and the private key (d, n), then encrypts c = m^e mod n and
 * decrypts m = c^d mod n. Uses plain long long, so it's for learning only -
 * real RSA uses primes with hundreds of digits.
 *
 * Time:   O(sqrt(p) + log e) per step, roughly
 * Memory: O(1)
 *
 * Input:  a number m with 0 <= m < n (n is printed, it's always > 10^6)
 * Output: the keys, the encrypted number and the decrypted one
 *
 * Example: echo "123456" | ./rsa
 */
// needs C++17 (structured bindings)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

#define ll long long

bool is_prime(ll num){
    if (num == 1 || num == 0)
		return false;
	for (ll i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	
	return true;
}

std::pair<ll, ll> generate_prime_numbers(ll low_lim, ll upper_lim){
    ll first_num = 0;
    ll second_num = 0;
    do {
        first_num = low_lim + (rand() % upper_lim);
        second_num = low_lim + (rand() % upper_lim); 
    // p and q must be two *different* primes, otherwise phi(n) != (p - 1)(q - 1)
    } while (!is_prime(first_num) || !is_prime(second_num) || first_num == second_num);
    
    return std::make_pair(first_num, second_num);
}

ll phi(ll p, ll q){
    return (p - 1) * (q - 1);
}

ll gcd(ll first, ll second){
    if(first == 0)
		return second;
	else if (second == 0)
		return first;
	else
		return gcd(second, first % second);
}

ll find_coprime(ll phi_res){
    ll e = 2;
    while (e < phi_res){
        ll gcd_res = gcd(e, phi_res);
        if (gcd_res == 1)
            return e;
        e++;
    }
    
    return e;
}

ll calculate_d(ll phi_res, ll e){
    ll k = 1;
    ll d = 0;
    
    while ((((k * phi_res) + 1) % e) != 0)
        k++;
    d = ((k * phi_res) + 1) / e;
    
    return d;
}

ll pow_mod(ll x, ll y, ll n){
    ll res = 1;
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

int main()
{
    srand(time(0));
    // from 1k to 10k
    ll m;
    std::cout << "Enter number for encryption and decryption" << std::endl;
    std::cin >> m;
    
    auto [p, q] = generate_prime_numbers(1000, 10000);
    ll n = p * q;
    if (m < 0 || m >= n){
        // RSA works on numbers modulo n, a bigger message can't be restored
        std::cout << "The number must be in range [0, " << n << ")" << std::endl;
        return 1;
    }
    ll phi_res = phi(p, q);
    ll e = find_coprime(phi_res);
    ll d = calculate_d(phi_res, e);
    
    std::cout << "(" << e << "," << " " << n << ") -- public key" << std::endl;
    std::cout << "(" << d << "," << " " << n << ") -- private key" << std::endl;
    /*
    (e, n) pair stands for public key, could be published anywhere
    (d, n) pair stands for private key and keeps in secret
    */
    // encrypted text (c) = m^e mod n
    ll c = pow_mod(m, e, n);
    std::cout << "encrypted text: " << c << std::endl;
    // decrypted text (m) = c^d mod n
    m = pow_mod(c, d, n);
    std::cout << "decrypted text: " << m << std::endl;
    return 0;
}
