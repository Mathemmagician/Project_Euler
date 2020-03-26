#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



int main() {
	int size = 2000000;
	
	int phis[size];
	int phisums[size];
	memset(phis, 0, sizeof(phis)); // FOR SOME REASON ARRAY NOT INITIALIZED TO ALL ZEROS
	//memset(phisums, 0, sizeof(phisums));
	phis[1] = 1;
	phisums[1] = 1;
	
	for (int i = 2; i < size; i++) {
		if (phis[i] == 0) {
			phis[i] = i - 1;
			for (int j = 2; i * j < size; j++) {
				if (phis[j] != 0) {
					int q = j;
					int f = i - 1;
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
	
	
	
	
	int q, L, R;
    set<float> slopes;

    cin >> q;
    while (q > 0) {
        q--;
        scanf("%d %d", &L, &R);

        if (R >= 2 * (L-1)) {
			cout << phisums[R] << endl;
		} else {
			slopes.clear();
			for (int x = L; x <= R; x++){
				for (int y = 1; y < x; y++){ // ignore 0, add at the end
					slopes.insert((float) y /  (float)x);
				}
			}
			cout << (slopes.size()+1) << endl; // Plus 1 for zero
		}
    }  
    return 0;
}
