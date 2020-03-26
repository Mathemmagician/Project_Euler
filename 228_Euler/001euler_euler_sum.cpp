#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int phi(int n) {
	int result = n;
	for(int i=2; i*i <= n; i++) {
		if (n % i == 0) result -= result / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) result -= result / n;
	return result;
}

int phisum(int r) {
	// Assume L = 3. since R > 4, we will basically have L=2 and 1 so just sum from 1 to R
	int result = 0;
	for (int i = 1; i <= r; i++) {
		result += phi(i);
	}
	return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, L, R;
    set<float> slopes;

    cin >> q;
    while (q > 0) {
        q--;
        scanf("%d %d", &L, &R);

        if (R >= 2 * (L-1)) {
			cout << phisum(R) << endl;
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

