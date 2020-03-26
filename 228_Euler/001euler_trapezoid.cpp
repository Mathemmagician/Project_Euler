#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, L, R;
    int prev = 0;
    //int prevDiff;
    set<float> slopes;
    float slope;

    cin >> q;
    while (q > 0) {
        q--;
        //cin >> L >> R;
        scanf("%d %d", &L, &R);
        //cout << L << " " << R << endl;
        slopes.clear();
        for (int x = L; x <= R; x++){
            for (int y = 1; y < x; y++){ // ignore 0, add at the end
				slope = (float) y /  (float)x;
                slopes.insert(slope);
            }
        }

        cout << (slopes.size()+1) << endl; // Plus 1 for zero
		prev = slopes.size()+1;
    }  
    return 0;
}

