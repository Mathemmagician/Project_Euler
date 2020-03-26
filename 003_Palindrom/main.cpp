#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int FindLargestSmallerThanN(int n, vector<int> arr) {
	int low = 0, high = arr.size();
	while (low != high) {
		int mid = (low + high + 1) / 2;
		if (arr[mid] >= n) {
			high = mid - 1;
		}
		else {
			low = mid;
		}
	}
	return arr[low];
}

int main(){
    int t;
    cin >> t;
    vector<int> Ps; // Palindroms
    for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++){
                for (int c = 0; c <= 9; c++) {
                    Ps.push_back(11 * (9091 * a + 910 * b + 100 * c));
                }
            }
        }
    sort(Ps.begin(), Ps.end());
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << FindLargestSmallerThanN(n, Ps) << "\n";
    }
    return 0;
}


