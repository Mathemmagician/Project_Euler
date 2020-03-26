#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

//const int ssize = 100001; // 100,000
const int ssize = 13;
int primechk[ssize];
int eulerphi[ssize];
pair<double,int> resilience[ssize];

 
void preprocess(void)
{
    int i, j;
    eulerphi[1]=1;
    for(i=2 ; i < ssize ; i++)
    {
        eulerphi[i]=i;
        primechk[i]=1;
    }
    for(i=2 ; i < ssize ; i++)
    {
        if(primechk[i]==1)
        {
            eulerphi[i]-= eulerphi[i]/i;
            for(j=2 ; i*j < ssize ; j++)
            {
                primechk[i*j]=0;
                eulerphi[i*j]-=eulerphi[i*j]/i;
            }
        }
    }
    for (int d = 2; d < ssize; d++) {
		resilience[d] = {(double) eulerphi[d] / (d-1), d};
		//resilience[d] = eulerphi[d];
	}
}


int first_larger(pair<double,int> arr[], double target) {
	int start = 0;
	int ans = -1;
	int end = ssize;
	
	while (start <= end) {
		int mid = (start + end) / 2; 
  
        if (arr[mid].first <= target) 
            start = mid + 1; 
  
        else
        { 
            ans = mid; 
            end = mid - 1; 
        } 
	}
	return ans;
}

int smallest_d(pair<double,int> arr[], int lenn) {
	int minn = arr[2].second;
	int i = 3;
	while (i < lenn) {
		minn = min(minn, arr[i].second);
		i++;
	}
	return minn;
}


int main() {
	preprocess();
	
	sort(resilience, resilience + ssize);
	//for (int d = 0; d < 13; d++) {
		//cout << resilience[d].first << " " << resilience[d].second << endl;
	//}
	
	int T, a, b;
	double q;
	cin >> T;
	
	while (T > 0) {
		
		scanf("%d %d", &a, &b);
		q = (double) a / b;
		//cout << "q is " << q << endl;
		int cutoff = first_larger(resilience, q);
		//cout << "cutoff is " << cutoff << endl;
		
		cout << smallest_d(resilience, cutoff-1) << endl;
		// we want to find the smallest d on this interval
		//cout << min_element(resilience, resilience+cutoff) << endl;
		//pair<double,int> it = *min_element(resilience+2, resilience+cutoff);
		//cout << it.first << " " << it.second << endl;
		
		//cout << *d << endl;
		

		T--;
	}
	
	
    return 0;
}
