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

using namespace std;

void traveler(int N, int M, vector<int> &Dist, vector<vector<pair<int, int> > > &G) {
	
}

int main() {

	int N = 4;
	int M = 5;

	int u, v, w;

	cin >> N >> M;
	
	vector<vector<pair<int, int> > > G(20);
	vector<int> Dist;

	for (int i=0; i<M; i++) {
		
		cin >> u >> v >> w;

		pair<int,int> n1(v-65, w);
        pair<int,int> n2(u-65, w);
        
        G[u-65].push_back(n1);
        G[v-65].push_back(n2);
	}

	traveler(N, M, Dist, G);

	return 0;
}