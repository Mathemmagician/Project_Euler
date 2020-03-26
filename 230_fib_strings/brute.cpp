#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    string A, B, T;
    int a, b, temp;
    int n;
    cin >> q;
    while (q > 0) {
		cin >> A >> B >> n;
        //scanf("%s %s %d", A, B, n);
        a = A.size(); b = B.size();
        if (a >= n){
            cout << A[n-1] << endl;
        } else if (b >= n) {
            cout << B[n-1] << endl;
        } else {
            while (max(a,b) < n) {
                temp = a;
                a = b;
                b = temp + b;
                T = A;
                A = B;
                B = T + B;
                cout << "iteration ";
            }
            if (a >= n){
                cout << A[n-1] << endl;
            } else {
                cout << B[n-1] << endl;
			}
		}
        q--;
	}
    return 0;
}
