/*
Description:
In BeagleTown live some beagles in their own doghouses, Prue who is the Sparko’s girlfriend is preparing a birthday party for him, 
and she wants everybody in town be part of the party, but she is going to prepare a gourmet dinner and she needs to confirm the 
assistance of each one in BeagleTown, that why she needs to go to the doghouse of each one and return to her house to start to 
prepare the dinner as soon as possible.

Help Prue to go to all the doghouses and return her doghouse in the shortest time. Prue lives in the doghouse A.

Input
	The first line in the input contains two integers N, M(2<=N<=20, 1<=M <=5000), the number of doghouses (N) and the number of 
	roads (M). Then came the M lines, one per road with 2 characters and integer that means the distance between those doghouses.

Output
	Print a line containing the minimal distance that Prue needs to visit all the doghouses and return her doghouse. Print INF in 
	case that there not are a posible way.

Sample Input:
	4 5
	A B 5
	A C 10
	A D 8
	B C 2
	C D 1

Sample Output:
	16
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int INF = INT_MAX;

void findPath(vector<vector<int> > houses, vector<int> P, int &adder) {

	int size = houses.size();			// Number of houses
	vector<bool> check(size);			// Houses already checked
	int minimalCost = INF;				// Minimum cost of path
	
	for (int i=1; i<size; i++) {
		check[P[i]] = true;
		adder += houses[P[i]][P[i]];
	}

	if (size == P.size()) {
		adder += houses[P.back()][0];
		return;
	}

	for(int i=1; i<size; i++){
        minimalCost = ((houses[P.back()][i] < minimalCost) && !check[i]) ?
        	houses[P.back()][i] : minimalCost;	
    }

    adder = (minimalCost == INF) ?
    	INF : adder+minimalCost;
	
	if (adder == INF)
		return; 

	for(int i=1; i<size; i++){
        
		minimalCost = INF;

        if(!check[i]) {
	        
	        for(int j=0; j<size; j++){
	            
	            if(!check[j] &&  minimalCost > houses[i][j]){
	                minimalCost = houses[i][j];
	            }
	        }
	        if(minimalCost == INF){
	            adder = INF;
	            break;
	        } else {
	            adder += minimalCost;
	        }
	    }
    }	
}

// Traveler salesman problem solved 
int traveler(priority_queue<pair<int,vector<int> >, 
	vector<pair<int,vector<int> > >, 
	greater<pair<int,vector<int> > > > pQ, vector<vector<int> > houses) {
	
	int minimalCost = INF;

	// Search in all the posible paths
	while (!pQ.empty()) {
		
		if (minimalCost > pQ.top().first) {
			
			vector<bool> check(houses.size());
			int size = pQ.top().second.size();
			int cost = pQ.top().first;
			bool flag = true;

			for (int i=1; i<size; i++) {
				check[pQ.top().second[i]] = true;
			}

			if (size == houses.size()) {

				if (minimalCost>cost && flag) {
					minimalCost = cost;
					flag = false;
				}
			}

			if (flag) {

				for(int i=1; i<houses.size(); i++){
					
					if (houses[pQ.top().second.back()][i] != INF && !check[i]) {
						vector<int> P(pQ.top().second);
						P.push_back(i);

						int adder = 0;
						// findPath(houses, P, adder);

						if (adder != INF) {

						}
					}	
				}
			}
		}

		pQ.pop();
	}

	return minimalCost;
}

int main() {

	int N;						// number of Houses	
	int M;						// Querys

	char u, v;					// Houses
	int w; 						// Distance

	int minimalCost = 0;		// Minimal cost to travel
	int minimmum = INF;		// Minimum value of the distances

	// Distance between places
	vector<int> distance;

	// Auxiliar Priority Queue
	priority_queue<pair<int,vector<int> >, 
		vector<pair<int,vector<int> > >, 
		greater<pair<int,vector<int> > > > pQ;

	// Asf for Number of houses and querys
	cin >> N >> M;
	
	// Distances between houses
	vector<vector<int> > houses(N, vector<int>(N, INF));

	// Ask for distances
	for (int i=0; i<M; i++) {
		
		cin >> u >> v >> w;

		houses[u-65][v-65] = w;
		houses[v-65][u-65] = w;
	}
	
	distance.push_back(0);

	for(int i=0; i<houses.size(); i++){
        
        for(int j=0; j<houses.size(); j++){
            
            minimmum = (houses[i][j] < minimmum) ?
            	houses[i][j] : minimmum;
        }
        
        minimalCost += minimmum;
        minimmum = INF;
    }

    pQ.push(make_pair(minimalCost, distance));

    int res = traveler(pQ, houses);

    (res == INF) ?
    	cout << "INF" << endl : cout << res << endl;

    // End program
	return 0;
}
