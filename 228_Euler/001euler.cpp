#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


// pair reduced(int a, int b){

// }

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, L, R, temp;
    int prev;
    set<pair<int,int>> reduced;
    pair<int, int> paaair;

    cin >> q;
    while (q > 0) {
        q--;
        cin >> L >> R;
        //cout << L << " " << R << endl;
        reduced.clear();
        for (int i = L; i <= R; i++){
            for (int j = 1; j < i; j++){ // ignore 0, add at the end
				//cout << i << " " << j << endl;
                temp = gcd(i, j);
                paaair.first = i / temp;
                paaair.second = j / temp;
                reduced.insert(paaair);
            }
        }
		
		//for(auto f : reduced) {
		//  cout << f.second << "/" << f.first << ", ";
		//} cout << endl;
		
		
        cout << (reduced.size()+1) << " +" << prev << "To previous" << endl; // Plus 1 for zero
		prev = reduced.size()+1;
    }  
    return 0;
}

