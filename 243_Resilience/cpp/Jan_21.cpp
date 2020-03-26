#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long
#define bi __int128



std::ostream&
operator<<( std::ostream& dest, __int128 value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __int128 tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}



const int ssize = 200;
bi primorals[ssize];
int primes[ssize];
int primechk[21000];
 
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

void my_preprocess() {
	primes[0] = 1;
	primorals[0] = 1;
	
	int i = 1;
	int num = 1;
	while (i < ssize) {
		if (primechk[num] == 1) {
			primes[i] = num;
			primorals[i] = primorals[i-1] * num;
			cout << "i=" << i << " " << primorals[i] << endl;
			i++;
		}
		num++;
	}
}


int main() {
	preprocess();
	my_preprocess();

	for (int i = 0; i < ssize; i++) {
		cout <<  primes[i] << " ";
		
	}
	
	
	
	return 0;
}


















