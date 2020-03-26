#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long
#define ull unsigned long long

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

//                 1000001 million
const int ssize =  4000001; // 2x10^5 which squared gives 4x10^10
int eulerphi[ssize];
int primechk[ssize];
ll eulersum[ssize];
map<ll, ll> bigsums;

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

ull phisum(ll n) {
	if (n < ssize)
		return eulersum[n];
	
	if (bigsums.find(n) != bigsums.end())
		return bigsums[n];
	
	ull temp;
	int u = (int) sqrt(n);
	
	if (n % 2 == 0)
		temp = n / 2 * (n+1);
	else
		temp = (n+1) / 2 * n;
	
	for (ll i=1; i <= n/(u+1); i++) {
		temp -= (n / i) * eulerphi[i]; 
	}
	
	for (ll d=2; d <= u; d++) {
		temp -= phisum(n/d); 
	}
	
	temp += u * eulersum[n/(u+1)];
	
	bigsums.insert({n, temp});
	return temp;
}




int main() {
	preprocess();
	//for (int i =2; i<30;i++)
	//	cout << eulersum[i]/2 << " ";
	
	//cout << phisum(100) << endl;; // 10^9
    
    cout << phisum(1000000000) << endl;; // 10^9
    
	//cout << phisum(3900000000); // 10^9



return 0;
}
