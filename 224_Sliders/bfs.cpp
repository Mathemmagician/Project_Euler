
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;





int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    int r,c, rr, cc;
    vector<string> history;
    vector<string> queue;
    vector<string> new_queue;
    vector<pair<int,int>> rowcol_queue;
    vector<pair<int,int>> new_rowcol_queue;
    
    
    cin >> n;
    char tempchar;
    string in_str;
    string final_str;
    string current_str;
    string new_str;
    
    
    for (int i=0;i<n;i++) {
		for (int j=0; j<n; j++) {
			cin >> tempchar;
			in_str += tempchar;
			if (tempchar == 'W'){
				r = i;
				c = j;
			}
		}
	}
	queue.push_back(in_str);
	rowcol_queue.push_back(make_pair(r,c));
	for (int i=0;i<n;i++) {
		for (int j=0; j<n; j++) {
			cin >> tempchar;
			final_str += tempchar;
		}
	}
	cout << final_str << endl;
	
	int dr[4]{-1, +1, 0, 0};
    int dc[4]{0, 0, +1, -1};
    
    while (find(history.begin(), history.end(), final_str) != history.end()) {
		while (!queue.empty()) {
			current_str = queue.front();
			queue.erase(queue.begin());
			current_rc = rowcol_queue.front();
			r = current_rc.first;
			c = current_rc.second;
			rowcol_queue.erase(rowcol_queue.begin());
			
			for (int i = 0; i < 4; i++){
				rr = r + dr[i];
				cc = c + dc[i];
				if ((rr < 0) or (cc < 0) or (rr >= n) or (cc >= n)) {
					continue; // new values must be from 0 to n-1
				} else {
					new_str = 
				}
			}
		}
	}
    
    
      
    return 0;
}
