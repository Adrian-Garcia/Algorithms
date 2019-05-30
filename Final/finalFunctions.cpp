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
	
			for (int j=0; j<c; j++) {z
	
				if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > max(D[i][k],D[k][j])){
					D[i][j] = max(D[i][k],D[k][j]); 
				}
			}
		}
	}
}

int cuttingSticks(int ci[], int l , int n) {

	int Matrix[50][50];

	for (int i=1; i<=n; i++) {

		for (int j=i-1; j>=0; j--) {

			if (j+1 == i) 
				Matrix[j][i] = 0;

			else {

				Matrix[j][i] = INT_MAX;

				for (int k=j+1; k<i; k++) {

					if (Matrix[j][i] > Matrix[j][k]+Matrix[k][i])
						Matrix[j][i] = Matrix[j][k]+Matrix[k][i];
				}

				Matrix[j][i] += ci[i] - ci[j];
			}
		}
	}

	//Regresamos valor
	return Matrix[0][n];
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
        for (int j=1; j<=i; j++) {
            v[i] += v[i-j]*v[j-1];
        }
    }

    // Regresamos ultimo valor del vector
    return v[n];
}

int LCS(string a, string b) {

	int aSize = a.length();
	int bSize = b.length();

	int Mat[aSize+1][bSize+1];

	for (int i=0; i<=aSize; i++)
		Mat[i][0] = 0;

	for (int i=0; i<=bSize; i++)
		Mat[0][i] = 0;

	for (int i=1; i<=aSize; i++) {
		
		for (int j=1; j<=bSize; j++) {
			
			if (a[i-1] == b[j-1])
				Mat[i][j] = Mat[i-1][j-1]+1;

			else 
				Mat[i][j] = max(Mat[i][j-1], Mat[i-1][j]);
		}
	}

	return Mat[aSize][bSize];
}

double median(double arr1[], double arr2[], int n) {

	if (n<=0) 
		return 0; 
	
	if (n==1) 
		return (arr1[0] + arr2[0]) / 2; 

	if (n==2) 
		return (min(arr1[1], arr2[1]) + max(arr1[0], arr2[0])) / 2;

	int medianArr1 = (n%2==0) ? 
		(arr1[n/2]+arr1[n/2-1])/2 : arr1[n/2];

	int medianArr2 = (n%2==0) ? 
		(arr2[n/2]+arr2[n/2-1])/2 : arr2[n/2];	
	
	if (medianArr1 < medianArr2) {
		
		return (!n%2) ?
			median(arr1+n/2-1, arr2, n-(n/2)+1):
			median(arr1+n/2, arr2, n-(n/2));
	}
	
	else if (medianArr1 == medianArr2) {
		return medianArr1;
	}

	if (!n%2) {
		return median(arr2+n/2-1, arr1, n-(n/2)+1);
	}

	else {
		return median(arr2+n/2, arr1, n-(n/2));
	}	
}

bool railRoad(int N1, int N2, int train1[], int train2[], int order[]) {
	
	bool flag[N1+1][N2+1];					// To validate
	int i, j;								// Indexes

	flag[0][0] = true;

	for (i=0; i<N1; i++) {
		
		if (flag[i][0])
			flag[i+1][0] = (order[i+1]==train1[i+1]) ? true : false;

		else 
			flag[i+1][0] = false;
	}

	for (i=0; i<N2; i++) {
		
		if (flag[0][i]) 
			flag[0][i+1] = (order[i+1]==train2[i+1]) ? true : false;	

		else 
			flag[0][i+1] = false;
	}

	for (i=1; i<=N1; i++) {
		
		for (j=1; j<=N2; j++) {
			
			if (order[i+j] == train1[i] && flag[i-1][j])
				flag[i][j] = true;
			
			else if (order[i+j] == train2[j] && flag[i][j-1])
				flag[i][j] = true;

			else
				flag[i][j] = false;

		}
	}
	
	return flag[N1][N2];
}

void delSoldiers(int &rest, int soldiers[200000], int &index, int &alive) {
	
	if (alive > 0) {
		
		soldiers[index] -= rest;

		if (soldiers[index] < 0) {
			
			alive--;
			rest = abs(soldiers[index]);
			index++;
			delSoldiers(rest, soldiers, index, alive);
		}

		else if (soldiers[index] == 0) {
			
			alive--;
			index++;
			
			if (alive > 0) {
				cout << alive << endl;
			}
		}
		
		else {
			cout << alive << endl;
		}
	}
}

int kombat(int n, int k, int damage[], string buttons) {

	int res = 0;
	int counter = 0;
	char last = '@';
	priority_queue<int, vector<int>, greater<int> > hits;

	for (int i=0; i<n; i++) {
		
		if (buttons[i] != last) {
			
			last = buttons[i];
			counter = 1;
			
			while (!hits.empty()) {
				res += hits.top();
				hits.pop();
			}

			hits.push(damage[i]);
		}

		else if (counter < k) {
			
			hits.push(damage[i]);
			counter++;
		}

		else {

			if (hits.top() < damage[i]) {
				hits.pop();
				hits.push(damage[i]);
			}
			
			counter++;
		}
	}
	
	while (!hits.empty()) {
		res += hits.top();
		hits.pop();
	}

	return res;
}

int main() {

	return 0;
}