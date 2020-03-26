#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



int main() {
	long long size = 2000000;
	
	long long phis[size];
	//long long phisums[size];
	memset(phis, 0, sizeof(phis)); // FOR SOME REASON ARRAY NOT INITIALIZED TO ALL ZEROS
	//memset(phisums, 0, sizeof(phisums));
	phis[1] = 1;
	//phisums[1] = 1;
	
	for (long long i = 2; i < size; i++) {
		if (phis[i] == 0) {
			phis[i] = i - 1;
			for (long long j = 2; i * j < size; j++) {
				if (phis[j] != 0) {
					long long q = j;
					long long f = i - 1;
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
	
	
	int q, L, R;
	long long temp;

    cin >> q;
    while (q > 0) {
        q--;
        scanf("%d %d", &L, &R);

		if (R == L) {
			cout << R << endl;
		} else if (R >= 2 * (L-1)) {
			temp = 0;
			for (long long i = 1; i <= R; i++)
				temp += phis[i];
			cout << temp << endl;
		} else {
			temp = 0;
			for (long long i = 1; i <= R; i++)
				temp += phis[i];
			for (long long i = R-L+1; i < L; i++){
				if (R/i == (L-1)/i)
					temp -= phis[i];
			}
			cout << temp << endl;
		}
    }  
    return 0;
}
