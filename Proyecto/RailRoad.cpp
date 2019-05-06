/*
Description
A train yard is a complex series of railroad tracks for storing, sorting, or loading/unloading railroad cars. In this problem, 
the railroad tracks are much simpler, and we are only interested in combining two trains into one. The two trains each contain 
some railroad cars. Each railroad car contains a single type of products identified by a positive integer up to 1,000,000. The two 
trains come in from the right on separate tracks, as in the diagram above. To combine the two trains, we may choose to take the 
railroad car at the front of either train and attach it to the back of the train being formed on the left. Of course, if we have 
already moved all the railroad cars from one train, then all remaining cars from the other trainwill be moved to the left one at 
a time. All railroad cars must be moved to the left eventually. Depending on which train on the right is selected at each step, 
we will obtain different arrangements for the departing train on the left. For example, we mayobtain the order 1,1,1,2,2,2 by 
always choosing the top train until all of its cars have been moved. We may also obtain the order 2,1,2,1,2,1 by alternately 
choosing railroad cars from the two trains.

To facilitate further processing at the other train yards later on in the trip (and also at the destination), the supervisor at 
the train yard has been given an ordering of the products desired for the departing train. In this problem, you must decide 
whether it is possible to obtain the desired ordering, given the orders of the products for the two trains arriving at the train 
yard.

Input 
	The input consists of a number of cases. The first line contains two positive integers N1 N2 which are the number of railroad 
	cars in each train. There are at least 1 and at most 1000 railroad cars in each train. The second line contains N1 positive 
	integers (up to 1,000,000) identifying the products on the first train from front of the train to the back of the train. The 
	third line contains N2 positive integers identifying the products on the second train (same format as above). Finally, the 
	fourth line contains N1+N2 positive integers giving the desired order for the departing train (same format as above).The end 
	of input is indicated by N1 = N2 = 0

Output
	For each case, print on a line possible if it is possible to produce the desired order, or not possible if not.

Sample input
	3 3
	1 2 1
	2 1 1
	1 2 1 1 2 1
	3 3
	1 2 1
	2 1 2
	1 1 1 2 2 2
	0 0

Sample Output
	possible
	not possible
*/
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

bool validate(int N1, int N2, int train1[], int train2[], int order[]) {
	
	bool flag[N1+1][N2+1];					// To validate
	int i, j;								// Indexes

	// Asume initial value as true
	flag[0][0] = true;

	// First Column
	for (i=1; i<=N1; i++) {
		
		if (flag[i-1][0]) {

			flag[i][0] = (order[i]==train1[i]) ? true : false;
		}

		else {

			flag[i][0] = false;
		}
	}

	// First row
	for (i=1; i<=N2; i++) {
		
		if (flag[0][i-1]) {

			flag[0][i] = (order[i]==train2[i]) ? true : false;
		}		

		else {

			flag[0][i] = false;
		}
	}

	cout << endl << endl;
	for (int a=0; a<N1+1; a++) {
		for (int b=0; b<N2+1; b++) {
			cout << flag[a][b] << " ";
		} cout << endl;
	} cout << endl << endl;

	// Internal matrix
	for (i=1; i<=N1; i++) {
		
		for (j=1; j<=N2; j++) {
			
			// Validate positions
			if (order[i+j] == train1[i] && flag[i-1][j]) {
				flag[i][j] = true;
			} else if (order[i+j] == train2[j] && flag[i][j-1]) {
				flag[i][j] = true;
			} else {
				flag[i][j] = false;
			}
		}
	}
	
	cout << endl << flag[N1][N2] << endl;

	// Return last value of the matrix
	return flag[N1][N2];
}

int main() {

	int cases; 			// Cases 
	int N1;	 			// Size of train 1
	int N2;				// Size of train 2

	cin >> N1 >> N2;

	while (N1 != 0 && N2 != 0)	{

		int train1[N1];		// Train1
		int train2[N2];		// Train2
		int order[N1+N2];	// Order of vagons

		// Ask for train 1
		for (int i=0; i<N1; i++) {
			cin >> train1[i];
		}

		// Ask for train 2
		for (int i=0; i<N2; i++) {
			cin >> train2[i];
		}

		// Ask for order
		for (int i=0; i<N1+N2; i++) {
			cin >> order[i];
		}

		validate(N1, N2, train1, train2, order) ? 
			cout << "possible" << endl:
			cout << "not possible" << endl;

		// Ask new size of trains
		cin >> N1 >> N2;
	}

	// End program
	return 0;
}
