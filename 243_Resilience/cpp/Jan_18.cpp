#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

const int ssize = 100010; // 100,000
//const int ssize = 13;
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
    resilience[0] = {1.5, 0};
    resilience[1] = {1.5,1};
    int count = 0;
    for (int d = 2; d < ssize; d++) {
		if (((double) eulerphi[d]) / (d-1) == 1)
			count++;
		resilience[d] = {((double) eulerphi[d]) / (d-1), d};
	}
	cout << "THERE ARE " << count << " MANY ONES" << endl;
}

int smallest_d(pair<double,int> arr[], double ratio) {
	int d = ssize;
	int i = 0;
	while (arr[i].first < ratio) {
		d = min(d, arr[i].second);
		i++;
	}
	return d;
}


int main() {
	preprocess();
	
	sort(resilience, resilience + ssize);
	for (int d = ssize-13-9593; d < ssize-9593; d++) {
		cout << resilience[d].first << " " << resilience[d].second << endl;
	}
	
	int T, a, b;
	double q;
	cin >> T;
	
	while (T > 0) {
		
		scanf("%d %d", &a, &b);
		q = (double) a / b;

		cout << smallest_d(resilience, q) << endl;

		T--;
	}
	
	
    return 0;
}
