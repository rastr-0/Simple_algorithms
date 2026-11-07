/*
This is an example of RSA realisation.
In this code I do not use libraries for big numbers.
But functions designed in a good way to work with big numbers.
*/

// should be compiled with c++17
#include <iostream>
#include <ctime>

#define ll long long

bool is_prime(ll num){
    if (num == 1 || num == 0)
		return false;
	for (int i = 2; i * i <= num; i++)
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
    } while (!is_prime(first_num) || !is_prime(second_num));
    
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
    ll phi_res = phi(p, q);
    ll e = find_coprime(phi_res);
    ll d = calculate_d(phi_res, e);
    
    std::cout << "(" << e << "," << " " << n << ") -- public key" << std::endl;
    std::cout << "(" << e << "," << " " << d << ") -- private key" << std::endl;
    /*
    (e, n) pair stands for public key, could be published anywhere
    (e, d) pair stands for private key and keeps in secret
    */
    // encrypted text (c) = m^e mod n
    ll c = pow_mod(m, e, n);
    std::cout << "encrypted text: " << c << std::endl;
    // decrypted text (m) = c^d mod n
    m = pow_mod(c, d, n);
    std::cout << "decrypted text: " << m;
    return 0;
}
