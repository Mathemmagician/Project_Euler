#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

ll phi(ll n) {
    //if (n < ssize)
    //    return eulerphi[n];
    
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


bool is_prime(ll n) {
    if (n == 1) {
        return false;
    }

    ll i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}


bool coresilient(ll n) {  
	if (is_prime(n))
		return true;
    ll num = n - phi(n);
    ll den = n - 1;
    if (den % num == 0)
        return true;
    
    return false;
}



int main() {
    
    ll N;   // 2 <= N <= 10^11
    cin >> N;
    N = 1000000;
    
    ll count = 0;
    for (ll n = 2; n <= N; n++) {
        if (coresilient(n))
            count += n;
    }
    
    cout << count << endl;
    
    return 0;
}
