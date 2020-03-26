#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

int primechk[2000100];
 
void preprocess(void)
{
    int i, j;
    for(i=2 ; i<=20000 ; i++)
    {
        primechk[i]=1;
    }
    for(i=2 ; i<=20000 ; i++)
    {
        if(primechk[i]==1)
        {
            for(j=2 ; i*j<=20000 ; j++)
            {
                primechk[i*j]=0;
            }
        }
    }
}

ll phi(ll n) {
	//if (n < ssize)
	//	return eulerphi[n];
	
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

ll gcd(ll u, ll v) {
    return u%v==0?v:gcd(v,u%v);
}



bool coresilient(ll n) {	
	ll num = n - phi(n);
	ll den = n - 1;
	if (num / gcd(num, den) == 1)
		return true;
	
	return false;
}


int main() {
	preprocess();
	
	int t=2;
	int prev = 0;
	while (t < 5000) { 
	
	ll N;   // 2 <= N <= 10^11
	//cin >> N;
	N = t;
	
	ll count = 0;
	for (ll n = 2; n <= N; n++) {
		if (coresilient(n))
			count += n;
	}
	
	if (prev != count) {
		if (primechk[N] == 0) {
			ll x = (N-1) / (N-phi(N));
			printf("%04lld, %04lld, %02lld\n", N, phi(N), x);
		}
	}
	//if (prev != count) {
		//if (primechk[N] == 0)	 {
			//cout << "NOT PRIME " << N << endl;
			//cout << " phi = " << phi(N) << " gcd= " << gcd(N - phi(N), N-1) <<  endl;
		//} else{
		//cout << "n= " << N << " count= " << count << endl;
			//cout << N << endl;
		//}
	//}
	prev = count;
	t++;
	
}	
	
    return 0;
}
