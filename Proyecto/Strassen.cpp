/*
Description
Given two squared matrices A and B, execute the multiply A x B with the algorithm of:
	• Traditional
	• Strassen

Display the number of scalar multiplications.

Input
	First comes n (4 <= n <=128) the dimension of the squared matrices, and then comes n
	rows with n integers of the matrix A, then comes n rows with n integer of the matrix B.

Output
	The number of scalar multiplications in traditional matrix multiplication and the number
	of scalar multiplications in Strassen matix multiplication. Check the output format in the


Sample Input
	4
	1 2 3 4
	5 6 7 8
	9 10 11 12
	13 14 15 16
	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 0 1

Sample Output.
*/
#include <iostream>

using namespace std;



int traditional(int n, int matA[20][20], int matB[20][20]) {
	
	int multiplications = 0;

	return multiplications;
}

int strassen(int n, int mat[20][20], int matB[20][20]){
	int multiplications = 0;

	return multiplications;
}

int main() {

	int n; 				// Size of matrix
	int matA[20][20];	// Matrix A
	int matB[20][20];	// Matrix B
	
	cin >> n;	

	// Ask matrix A
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> matA[i][j];
		}
	}

	// Ask matrix B
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> matB[i][j];
		}
	}

	// Display results
	cout << "Traditional Scalar Multiplications: " << traditional(n, matA, matB) << endl;
	cout << "Strassen Scalar Multiplications: " << strassen(n, matA, matB) << endl;

	// End program
	return 0;
}