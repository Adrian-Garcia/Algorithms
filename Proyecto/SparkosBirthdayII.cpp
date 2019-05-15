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

int findPath(vector<vector<int> > houses, vector<int> P) {

	int adder = 0;
	vector<bool> check(houses.size());			// Houses already checked
	
	for(int i=1; i<P.size(); i++){
        adder += houses[P[i]][P[i-1]];
        check[P[i]] = true;
    }

	if (houses.size() == P.size()) 
		return adder + houses[P.back()][0];

	int minimalCost = INF;
	for(int i=1; i<houses.size(); i++) {
		if ((houses[P.back()][i] < minimalCost) && !check[i]) {
			minimalCost = houses[P.back()][i];	
		}
	}

    if (minimalCost == INF) 
    	return INF;
    else 
    	adder += minimalCost;
	
	for(int i=1; i<houses.size(); i++){

		if (check[i]) 
			continue;
		
		minimalCost = INF;
        
        for(int j=0; j<houses.size(); j++) {
        	
        	if (houses[i][j] < minimalCost && !check[j]) 
        		minimalCost = houses[i][j];
        }

        if(minimalCost == INF){
            adder = INF;
            break;
        } else {
            adder += minimalCost;
        }
    }	

    return adder;
}

// Traveler salesman problem solved 
int traveler(priority_queue<pair<int,vector<int> >, vector<pair<int,vector<int> > >, greater<pair<int,vector<int> > > > pQ, vector<vector<int> > houses) {
	
	int minimalCost = INF;

	// Search in all the posible paths
	while (!pQ.empty()) {

		pair<int,vector<int> > top = pQ.top();
		pQ.pop();

		if (minimalCost < top.first)
			continue;

		vector<bool> check(houses.size());

		for (int i=1; i<top.second.size(); i++) 
			check[top.second[i]] = true;

		if (top.second.size() == houses.size()) {
			
			int cost = top.first;
			
			if (minimalCost > cost){
				minimalCost = cost;
			}

			continue;
		}
		
		for(int i=1; i<houses.size(); i++){
			
			if (houses[top.second.back()][i] != INF && !check[i]) {
				
				vector<int> P(top.second);
				P.push_back(i);

				int adder = findPath(houses, P);
				
				if (adder != INF) 
					pQ.push(make_pair(adder,P));
			}
		}
	}

	// Return smallest path of houses 
	return minimalCost;
}

int main() {

	int N;						// number of Houses	
	int M;						// Querys

	char u, v;					// Houses
	int w; 						// Distance

	int res;					// Final Result

	// Asf for Number of houses and querys
	cin >> N >> M;
	
	// Distances between houses
	vector<vector<int> >  houses(N, vector<int>(N));

	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            houses[i][j] = INF; 
        }
    }

	// Ask for distances
	for (int i=0; i<M; i++) {
		
		cin >> u >> v >> w;

		houses[u-'A'][v-'A'] = w;
		houses[v-'A'][u-'A'] = w;
	}

	vector<int> distance;
	distance.push_back(0);
	
	priority_queue<pair<int,vector<int> > , 
		vector<pair<int,vector<int> > >, 
		greater<pair<int,vector<int> > > > pQ;

	int minimalCost = 0;
	int minimmum;	

	for(int i=0; i<houses.size(); i++){
        
        minimmum = INF;

    	for (int j=0; j<houses.size(); j++) {

    		if(houses[i][j] < minimmum) {
                minimmum = houses[i][j];
    		}
    	}
        
        minimalCost += minimmum;
    }

    pQ.push(make_pair(minimalCost, distance));

    res = traveler(pQ, houses);

    if (res != INF) 
    	cout << res << endl;
    else
    	cout << "INF" << endl;

    // End program
	return 0;
}