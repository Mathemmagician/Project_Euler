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

//                1000000 1 million
const ll ssize =  4000000;
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
	ll r;
	if (n % 2 == 0)
		temp = n / 2 * (n+1);
	else
		temp = (n+1) / 2 * n;
	
	// d == 1
	if (1 != n)
		temp -= (n - n/2) * eulerphi[1];
	
	for (ll m = 2; m*m <= n; m++) {
		r = n/m;
		temp -= phisum(r);
		if (m == r)
			continue;
		temp -= (r - n/(m+1)) * phisum(m);
	}
	
	//for (ll d = 1; d*d <= n; d++) {
		//if (d == n/d)
			//continue;
		//temp -= (n/d - n/(d+1)) * phisum(d);
	//}
	return temp;
}




int main() {
	preprocess();
	//for (int i =2; i<30;i++)
	//	cout << eulersum[i]/2 << " ";
	
    cout << phisum(1000000000); // 10^9
	//cout << phisum(3900000000); // 10^9



return 0;
}
