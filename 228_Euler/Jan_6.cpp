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
__int128 eulersum[ssize];
unordered_map<ull, __int128> bigsums;


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


ull phi(ull n) {
	if (n < ssize)
		return eulerphi[n];
	
    ull result = n;
    for (ull i = 2; i * i <= n; i++) {
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


__int128 phisum(ull n) {
    if (n < ssize)
        return eulersum[n];
    
    if (bigsums.find(n) != bigsums.end())
        return bigsums[n];
    
    __int128 temp;
   
    int u = (int) sqrt(n);

    temp = n * (n+1) / 2;
    
    temp += u * phisum(n/(u+1));

    for (ull i=1; i <= n/(u+1); i++) {
        //temp -= (n / i) * eulerphi[i]; 
        temp -= (n/i) * phi(i);
    }			
    
    for (ull d=2; d <= u; d++) {
		//temp -= phisum(n/d); 
		__int128 tempp = phisum(n/d);
		if (tempp > temp) {
			cout <<"WARNING. (n/d) = " << (n/d) << "\t";
		}
		temp -= tempp;
		
        	
    }
    

    

    
    bigsums[n] = temp;
    return temp;
}



int main() {
    preprocess();
    
    int t;
    ull L, R, M;
    
    cin >> t;

    //ull temp;
    __int128 bigtemp;

    for (int ti = 0; ti < t; ti++){
        scanf("%llu %llu\n", &L, &R);
        M = L-1;


		if (R>6000000000) cout << "here";
        //if (R>6000000000) {
            bigtemp = phisum(R);
            ull x,y;
            
            
            x = bigtemp % 1000000000000000000;
            y = bigtemp / 1000000000000000000;
            cout << "bigsum  ";
            if (y == 0)
                printf("%llu\n", x);
            else
                printf("%llu%018llu\n", y,x);
			cout << "\t\t";
       
            
            ull i = 2;
            ull limit = sqrt(R);
            while ((R/i <= M/(i-1)) and (R/i >= limit)) {
                bigtemp -= phisum(M/(i-1)) - phisum(R/i);
                i++;
            }
            
            
            if (R/i < limit) {
                for (ull k = R-M; k <= R/(i-1); k++){
                    if (R/k == M/k) {
                        bigtemp -= eulerphi[k];
                    }
                }
            }
            x = bigtemp % 1000000000000000000;
            y = bigtemp / 1000000000000000000;
            if (y == 0)
                printf("%llu\n", x);
            else
                printf("%llu%018llu\n", y,x);
            

        //} else {
            //temp = phisum(R);
            
            //ull i = 2;
            //ull limit = sqrt(R);
            //while ((R/i <= M/(i-1)) and (R/i >= limit)) {
                //temp -= phisum(M/(i-1)) - phisum(R/i);
                //i++;
            //}
            
            //if (R/i < limit) {
                //for (int k = R-M; k <= R/(i-1); k++){
                    //if (R/k == M/k) {
                        //temp -= eulerphi[k];
                    //}
                //}
            //}
            //printf("%llu\n", temp);
        //}
    }

    return 0;
}
