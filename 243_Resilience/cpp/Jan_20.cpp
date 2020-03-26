#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define ll long long

const int ssize = 1000100; // 100,000
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
    for (int d = 2; d < ssize; d++) {
		resilience[d] = {((double) eulerphi[d]) / (d-1), d};
	}
}


int main() {
	preprocess();
	double min = 2;
	int diff = 0;
	int oldd = 1;
	int count = 0;
	
	for (int i = 2; i < 1000000; i++) {
		double R = resilience[i].first;
		int d = resilience[i].second;
		
		
		if (R < min) {
			min = R;
			//cout << "d=" << d << " R[d]=" << R << endl;
			if (d - oldd == diff){
				count++;
			} else {
				cout << "count= " << count << endl;
				count = 1;
				cout << "+" << diff << endl;
				diff = d-oldd;
			}
			oldd=d;
			//cout << d << " ";
		}
		
	}
	
    return 0;
}




















