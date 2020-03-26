#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    int r,c;
    //int rr, cc;
    char tempchar;
    cin >> n;
    
    int field[n][n];
    vector<int [n][n]> state;
    
    int goal[n][n];
    // 0 is whitespace, 1 is Red, 2 is Blue
    
    // north, south, east, west
    //int dr[4]{-1, +1, 0, 0};
    //int dc[4]{0, 0, +1, -1};
    
    for (int i = 0; i < n; i++) {
		for (int j=0; j < n; j++) {
			// Read in the field
			cin >> tempchar;
			if (tempchar == 'R') {
				field[i][j] = 1;
			} else if (tempchar == 'B') {
				field[i][j] = 2;
			} else if (tempchar == 'W') {
				field[i][j] = 0;
				r = i;
				c = j;
			} else {
				cout << "ERROR" << endl;
			}
		}
	}
	state.push_back(field);
	
	for (int i = 0; i < n; i++) {
		for (int j=0; j < n; j++) {
			// Read in the field
			cin >> tempchar;
			if (tempchar == 'R') {
				goal[i][j] = 1;
			} else if (tempchar == 'B') {
				goal[i][j] = 2;
			} else if (tempchar == 'W') {
				goal[i][j] = 0;
			} else {
				cout << "ERROR" << endl;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j=0; j < n; j++) {
			cout << field[i][j];
		}
		cout<<endl;
	}
    
    for (int i = 0; i < n; i++) {
		for (int j=0; j < n; j++) {
			cout << goal[i][j];
		}
		cout<<endl;
	}
	
	
    //for (int i = 0; i < 4; i++){
	//	rr = r + dr;
	//	cc = c + dc;
	//	if ((rr < 0) or (cc < 0) or (rr >= n) or (cc >= n)) {
	//		continue;
	//	}
		
      
    return 0;
}
