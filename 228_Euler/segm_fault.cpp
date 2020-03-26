#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int fi(int n) {
    int result = n;
    for(int i=2; i*i <= n; i++) {
        if (n % i == 0) result -= result / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) result -= result / n;
    return result;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, L, R;
    set<float> slopes;

    long m = 4e10;
    
    long fis[m];
    long fisums[m];
    fisums[0] = 0;
    
    for (long i = 1; i < m; i++) {
        fis[i] = fi(i);
        fisums[i] = fisums[i-1] + fis[i];
    }

    cin >> q;
    while (q > 0) {
        q--;
        scanf("%d %d", &L, &R);

        if (R >= 2 * (L-1)) {
            cout << fisums[R] << endl;
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

