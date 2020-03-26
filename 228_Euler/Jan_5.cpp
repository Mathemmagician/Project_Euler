#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define ll long long
#define ull unsigned long long

//                 1000001 million
const int ssize =  3000001; // 2x10^5 which squared gives 4x10^10
int eulerphi[ssize];
int primechk[ssize];
ull eulersum[ssize];
unordered_map<ll, ll> bigsums;

ull phi(ull n) {
    if (n < ssize)
        return eulerphi[n];
        
    ull result = n;
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

ull phisum(ull n) {
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
    
    for (ull i=1; i <= n/(u+1); i++) {
        temp -= (n / i) * eulerphi[i]; 
    }
    
    for (ull d=2; d <= u; d++) {
        temp -= phisum(n/d); 
    }
    
    temp += u * eulersum[n/(u+1)];
    
    bigsums[n] = temp;
    return temp;
}


int main() {
    preprocess();
    
    int t;
    ull L, R, M;
    
    cin >> t;

    ull temp;

    for (int ti = 0; ti < t; ti++){
        scanf("%llu %llu\n", &L, &R);
        M = L-1;
        temp = phisum(R);
        
        ull i = 2;
        ull limit = sqrt(R);
        if (bigsums.size() > 1000)
            bigsums.clear();
        while ((R/i <= M/(i-1)) and (R/i >= limit)) {
            temp -= phisum(M/(i-1)) - phisum(R/i);
            i++;
        }
        
        if (R/i < limit) {
            for (int k = R-M; k <= R/(i-1); k++){
                if (R/k == M/k) {
                    //cout << k << " " << R/i << "\t";
                    //if (i < ssize)
                        temp -= eulerphi[k];
                    //else
                    //    temp -= phi(k);
                }
            }
        }
        printf("%lld\n", temp);
        
    }

    return 0;
}
