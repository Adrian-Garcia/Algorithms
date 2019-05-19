/*
Final Functions
	
	Study guide with contain all the codes made at Algorythms subject
*/

#include <iostream>
#include <limits.h>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

#define INF INT_MAX
#define size 50;

void audiophobia (int D[size][size], int c) {

	for (int k=0; k<c; k++) {
		
		for (int i=0; i<c; i++) {
			
			for (int j=0; j<c; j++) {
				
				if (D[i][k] != INF && D[k][j] != INF && D[i][j] > max(D[i][k], D[k][j]))
					D[i][j] = max(D[i][k], D[k][j]);
			}
		}
	}
}

int cuttingSticks(int ci[], int l , int n) {

	int Mat[size];

	for (int i=1; i<=n; i++) {

		for (int j=i-1; j>=0; j--) {

			if (j+1 == i)
				Mat[j][i] = 0; 

			else {

				Mat[j][i] = INF;

				for (int k=j+1; k<i; k++) {
					
					if (Mat[j][k] + Mat[k][i] < Mat[j][i]) 
						Mat[j][i] = Mat[j][k] + Mat[k][i];

				}
			}

			Mat[j][i] += ci[i] - ci[j];
		}
	}

	return Mat[0][n];
}

void rockytheBeagle(int N, vector<int> &Dist, vector<vector<pair<int, int> > > &G) {
    
    priority_queue<pair<int, int>, 
        vector<pair<int, int> >, 
        greater<pair<int,int> > > Q;    

    Dist.assign(N, INF);
    Dist[0] = 0;
    pair<int, int> p(0, 0);
    Q.push(p);
    
    while (!Q.empty()) {
        
        int u = Q.top().first;
        Q.pop();

        for (int i=0; i<G[u].size(); i++) {
            
            pair<int, int> p = G[u][i];
            int v = p.first;
            int w = p.second; 
        
            if (Dist[v] > Dist[u]+w) {
                Dist[v] = Dist[u]+w;
                pair<int,int> nvo(v,Dist[v]);
                Q.push(nvo);
            }
        }
    }    
}

double howManyTrees(int n) {
	
	std::vector<double> v(n,0);
	v.insert(v.begin(), 1);

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; i++) {
			v[i] += v[i-j]*v[j-1];
		}
	}

	return v[n];
}

int LCS(string a, string b) {

	int Mat[a.length()+1][b.length()+1];

	// First Column
	for (int i=0; i<a.length(); i++)
		Mat[i][0] = 0;

	for (int i=0; i<b.length(); i++)
		Mat[0][i] = 0;

	for (int i=1; i<=a.length(); i++) {
		
		for (int j=1; i<=b.length(); j++) {

			if (a[i-1] == b[j-1]) 
				Mat[i][j] = Mat[i-1][j-1]+1;

			else 
				Mat[i][j] = max(Mat[i][j-1], Mat[i-1][j]);
		}
	}

	return Mat[a.length()][b.length()];
}

int main() {

	return 0;
}