#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using vi = vector<ll>;
using MAX = 10000000;

vi primes;
vi sieve(ll N) {
    vi primes(1, 2);
    bitset<MAX+1> is_prime;
    is_prime.set();

    for (ll i = 3; i <= N; i += 2) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(ll j = i * i; j <= N; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }
}

vi factors(ll N) {
    vi fac;
    for (ll i = 0; primes[i] <= sqrt(N); i++) {
        while(N % primes[i] == 0) {
            fac.push_back(primes[i]);
            N /= primes[i];
        }
    }

    if (N != 1) {
        fac.push_back(N);
    }
    return fac;
}

int main() {
    primes = sieve(10000000);

    ll N;
    cin >> N;
    vi fac = factors(N);
    for (auto i : fac) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
