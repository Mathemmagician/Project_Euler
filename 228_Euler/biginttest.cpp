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
	
	cout << eulersum[ssize-1] << endl;
    
    ull y,z;
    for (int i = 78100; i<78102+5; i++) {
		__int128 x = phisum(i);
		
		y = x % 100000000000;
		z = x / 100000000000;
		
		printf("%llu", z);
		printf(",%011llu\n",y);
	}	
    
    

	
	return 0;

}
