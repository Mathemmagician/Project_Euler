#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

const int ssize = 100001; // 100,000
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


double R(int d) {
	return (double) phi(d) / (d-1);
}



int main() {
	preprocess();
	
	int T, a, b, d;
	cin >> T;
	
	while (T > 0) {
		
		scanf("%d %d", &a, &b);
		
		d = 1;
		while (R(d) >= ((double)a) / b) {
			d++;
		}
		printf("%d", d);
		T--;
	}
	
	
    return 0;
}
