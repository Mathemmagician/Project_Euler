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

void updateFebs(long num, vector<long>&Evens, vector<long>&Sums) {
    long newElem;
    while (num > Evens.back()){
        newElem = Evens.rbegin()[1] + 4 * Evens.back();
        Evens.push_back(newElem);
        Sums.push_back(Sums.back() + newElem);
    }
}

long findMaxFibSmallerThanN(long n, vector<long>Evens, vector<long>Sums) {
	long low = 0, high = Evens.size();
	while (low != high) {
		long mid = (low + high) / 2;
		if (Evens[mid] >= n) {
			high = mid - 1;
		}
		else {
			low = mid;
		}
	}
	return Sums[low];
}

int main(){
    int t;
    vector<long> Evens{0,2};
    vector<long> Sums{0,2};
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        if (n > Evens.back()){
            updateFebs(n, Evens, Sums);
            cout << Sums.rbegin()[1] << endl;
        } else {
			cout << findMaxFibSmallerThanN(n, Evens, Sums) << endl;
		}
    }
    return 0;
}

