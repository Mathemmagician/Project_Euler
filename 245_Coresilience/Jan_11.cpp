#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

//const ll ssize = 200000000000; // 2x10^11
const ll ssize = 20000000; // 2x10^11
int primechk[ssize];
 
void preprocess(void)
{
    ll i, j;
    for(i=2 ; i< ssize ; i++)
    {
        primechk[i]=1;
    }
    for(i=2 ; i< ssize ; i++)
    {
        if(primechk[i]==1)
        {
            for(j=2 ; i*j< ssize ; j++)
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
	//if (num / gcd(num, den) == 1)
	if (den % num == 0)
		return true;
	
	return false;
}





int main() {
	preprocess();
	
	ll N;
	cin >> N;
	//N = 10000;
	ll count = 2;
	
	
	for (ll n = 3; n <= N; n+=2) {
		if (coresilient(n)) {
			count += n;
			//cout << n << " ";
			//cout << n << " " << count << endl;
			if (!primechk[n])
				printf("%lld\t", n);
			//cout << n << "\t";
		}
	}
	
	//cout << endl << "RESULT: " << count << endl;
	cout << count << endl;

	
    return 0;
}
