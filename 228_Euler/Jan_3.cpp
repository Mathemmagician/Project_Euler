#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long



ll phi(ll n) {
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

//               ,000,000
const ll ssize = 4000000;
ll eulerphi[ssize];
ll primechk[ssize];
ll eulersum[ssize];

void preprocess(void)
{
    int i, j;
    eulerphi[1]=1;
    eulersum[1]=1;
    for(i=2 ; i<ssize; i++)
    {
        eulerphi[i]=i;
        primechk[i]=1;
    }
    for(i=2 ; i<ssize ; i++)
    {
        if(primechk[i]==1)
        {
            eulerphi[i]-=eulerphi[i]/i;
            for(j=2 ; i*j<ssize ; j++)
            {
                primechk[i*j]=0;
                eulerphi[i*j]-=eulerphi[i*j]/i;
            }
        }
        eulersum[i] = eulersum[i-1] + eulerphi[i];
    }
}

ll phisum(ll n) {
	if (n < ssize)
		return eulersum[n];
	
	ll temp;
	if (n % 2 == 0)
		temp = n / 2 * (n+1);
	else
		temp = (n+1) / 2 * n;
	
	for (ll m = 2; m <= sqrt(n); m++) {
		temp -= phisum(n/m);
	}
	
	for (ll d = 1; d <= sqrt(n); d++) {
		if (d == n/d)
			continue;
		temp -= (n/d - n/(d+1)) * phisum(d);
	}
	return temp;
}





int main() {
	preprocess();
	
	int t;
    ll L, R;
    
    cin >> t;
    ll Ls[t];
    ll Rs[t];
    ll maxR = 0;
    
    for (int ti = 0; ti < t; ti++){
		scanf("%lld %lld", &L, &R);
		Ls[ti] = L;
		Rs[ti] = R;
		maxR = max(maxR, R);
	}
	
    ll temp;

	for (int ti = 0; ti < t; ti++){
		L = Ls[ti];
		R = Rs[ti];
		temp = phisum(R);
		
		for (ll i = R-L+1; i < L; i++){
			if (R/i == (L-1)/i) {
				if (i < ssize)
					temp -= eulerphi[i];
				else
					temp -= phi(i);
			}
		}
		printf("%lld\n", temp);
		
	}

    
    return 0;
}
