#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long phis[20000000];
long phisums[20000000];




int main() {
	int t;
    unsigned int L, R;
    long temp;
    
    cin >> t;
    long Ls[t];
    long Rs[t];
    
    for (int ti = 0; ti < t; ti++){
		scanf("%ld %ld", Ls[ti], Rs[ti]);
	}
    
    long size = *max_element(Rs, Rs+t);
    cout << "size is " << size;
    
    
    phis[1] = 1;
    phisums[1] = 1;
    
    for (long i = 2; i < size; i++) {
        if (phis[i] == 0) {
            phis[i] = i - 1;
            for (long j = 2; i * j < size; j++) {
                if (phis[j] != 0) {
                    long q = j;
                    long f = i - 1;
                    while (q % i == 0) {
                        f *= i;
                        q /= i;
                    }
                    phis[i * j] = f * phis[q];
                }
            }
        }
        phisums[i] = phisums[i-1] + phis[i];
    }
    
    for (int ti = 0; ti < t; ti++) {
        L = Ls[ti];
        R = Rs[ti];

        if (R == L) {
            cout << R << endl;
        } else if (R >= 2 * (L-1)) {
            cout << phisums[R] << endl;
        } else {
            //temp = phisums[R];
            temp = 0;
            for (int i = 0; i < R; i++){
				temp += phis[i];
			}
            for (unsigned int i = R-L+1; i < L; i++){
                if (R/i == (L-1)/i)
                    temp -= phis[i];
            }
            cout << temp << endl;
        }
    }  
    return 0;
}
