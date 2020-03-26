#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define ll long long
#define ull unsigned long long

//                 1000001 million
const int ssize =  4000001; // 2x10^5 which squared gives 4x10^10
int eulerphi[ssize];
int primechk[ssize];
ll eulersum[ssize];
unordered_map<ll, ll> bigphis;
unordered_map<ll, ll> bigsums;

ll phi(ll n) {
	if (n < ssize)
		return eulerphi[n];
		
    ll result = n;
    for (int i = 2; i * i <= n; i++) {
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
	
	int t;
    ll L, R, M;
    
    cin >> t;
    ll Ls[t];
    ll Rs[t];
    ll maxR = 0;
    
    for (int ti = 0; ti < t; ti++){
		scanf("%ulld %ulld", &L, &R);
		Ls[ti] = L;
		Rs[ti] = R;
		maxR = max(maxR, R);
	}
	
    ll temp;

	for (int ti = 0; ti < t; ti++){
		M = Ls[ti]-1;
		R = Rs[ti];
		temp = phisum(R);
		
		
		//if (R < ssize) {
		cout << L << " " << R << endl;
			//for (ll i = R-M; i <= M; i++){
				//if (R/i == M/i) {
					cout << i << " " << R/i << "\t";
					//if (i < ssize)
						//temp -= eulerphi[i];
					//else
						//temp -= phi(i);
				//}
			//}
		//} else {
			ll i = 2;
			while (R/i <= M/(i-1)) {
				temp -= phisum(M/(i-1)) - phisum(R/i);
				for (int j = R/i + 1; j <= M/(i-1); j++) {
					temp -= phi(j);
				}
				i++;
			}
		//}
		
		printf("%lld\n", temp);
		
	}

    return 0;
}
