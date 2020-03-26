#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long phis[40000000000];
//long long phisums[40000000000];

int main() {
    long long size = 40000000000;
    
    phis[1] = 1;
    //phisums[1] = 1;
    
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
        //phisums[i] = phisums[i-1] + phis[i];
    }
    
    
    int t;
    unsigned int L, R;
    long temp;

    cin >> t;
    while (t > 0) {
        t--;
        scanf("%u %u", &L, &R);

        if (R == L) {
            cout << R << endl;
        } else if (R >= 2 * (L-1)) {
            //cout << phisums[R] << endl;
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
