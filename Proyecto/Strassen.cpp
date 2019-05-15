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
	Traditional Scalar Multiplications: 64
	Strassen Scalar Multiplications: 56 
*/
#include <iostream>

using namespace std;

#define Z 80
int strassenMultiplication = 0;
int matD[Z][Z];

int traditional(int n, int matA[Z][Z], int matB[Z][Z]) { 

	int multiplications = 0;

	for (int i=0; i<n; i++) { 
		
		for (int j=0; j<n; j++) { 
			
			// No value for that direction
			matD[i][j] = 0; 
			
			for (int k=0; k<n; k++) { 
				matD[i][j]+=matA[i][k]*matB[k][j]; 
				multiplications++;
			} 
		} 
	}

	return multiplications; 
} 

// Sum for the matrix
void sum(int n, int matA[Z][Z], int matB[Z][Z], int matC[Z][Z]) {

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}
}

// Sub for the matrix
void sub(int n, int matA[Z][Z], int matB[Z][Z], int matC[Z][Z]) {

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			matC[i][j] = matA[i][j] - matB[i][j];
		}
	}
}

// Strassen Multiplication
void strassen(int n, int matA[Z][Z], int matB[Z][Z], int matC[Z][Z]) { 
	
	// Add one to the multiplications made to do strassen
	strassenMultiplication++;

	// End of partitioning
	if (n == 1) {
		matC[0][0] = matA[0][0] * matB[0][0];
		return;
	} 
	
	// To keep devidin
	int median = n/2;

	// Quartes of sub matrix A
	int matA00[Z][Z], matA01[Z][Z];
	int matA10[Z][Z], matA11[Z][Z];

	// Quartes of sub matrix B
	int matB00[Z][Z], matB01[Z][Z];
	int matB10[Z][Z], matB11[Z][Z];
	    
	// Quartes of sub matrix C
	int matC00[Z][Z], matC01[Z][Z]; 
	int matC10[Z][Z], matC11[Z][Z];
	    
	// Auxiliar matrixes
	int matAux1[Z][Z], matAux2[Z][Z]; 
	int matAux3[Z][Z], matAux4[Z][Z]; 
	int matAux5[Z][Z], matAux6[Z][Z]; 
	int matAux7[Z][Z];
	    
	// Resulting matrix
	int resMatA[Z][Z], resMatB[Z][Z];

	// Fill quarter of sub matrix
	for (int i=0; i<median; i++) {
	    	
		for (int j=0; j<median; j++) {

			matA00[i][j] = matA[i][j];
			matB00[i][j] = matB[i][j];
			matA01[i][j] = matA[i][j+median];
			matB01[i][j] = matB[i][j+median];

			matA10[i][j] = matA[i+median][j];
			matB10[i][j] = matB[i+median][j];

			matA11[i][j] = matA[i+median][j+median];
			matB11[i][j] = matB[i+median][j+median];
		}
	}

	// Solve Quartes
	sum(median, matA00, matA11, resMatA);
	sum(median, matB00, matB11, resMatB);
	strassen(median, resMatA, resMatB, matAux1);

	sum(median, matA10, matA11, resMatA);
	strassen(median, resMatA, matB00, matAux2);

	sub(median, matB01, matB11, resMatB);
	sub(median, matB01, matB11, resMatB);
	strassen(median, matA00, resMatB, matAux3);

	sub(median, matB10, matB00, resMatB);
	strassen(median, matA11, resMatB, matAux4);
	sum(median, matA00, matA01, resMatA);
	strassen(median, resMatA, matB11, matAux5);

	sub(median, matA10, matA00, resMatA);
	sum(median, matB00, matB01, resMatB);
	strassen(median, resMatA, resMatB, matAux6);

	sub(median, matA01, matA11, resMatA);
	sum(median, matB10, matB11, resMatB);
	strassen(median, resMatA, resMatB, matAux7);

	sum(median, matAux3, matAux5, matC01);
	sum(median, matAux2, matAux4, matC10);

	sum(median, matAux1, matAux4, resMatA);
	sum(median, resMatA, matAux7, resMatB);
	sub(median, resMatB, matAux5, matC00);

	sum(median, matAux1, matAux3, resMatA);
	sum(median, resMatA, matAux6, resMatB);
	sub(median, resMatB, matAux2, matC11);

	for (int i=0; i<median; i++) {
	    	
		for (int j=0; j<median; j++) {

			matC[i][j] = matC00[i][j];
			matC[i][j+median] = matC01[i][j];
			matC[i+median][j] = matC10[i][j];
			matC[i+median][j+median] = matC11[i][j];
		}
	}
}

int main() {

	int n;

	int matA[Z][Z];	// Matrix A
	int matB[Z][Z];	// Matrix B
	int matC[Z][Z]; // Matrix C
	
	cin >> n;	

	// Ask for matrix A
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> matA[i][j];
		}
	}

	// Ask for matrix B
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> matB[i][j];
		}
	}

	strassen(n, matA, matB, matC);

	// Display results
	cout << "Traditional Scalar Multiplications: " << traditional(n, matA, matB) << endl;
	cout << "Strassen Scalar Multiplications: " << strassenMultiplication-1 << endl;
	cout << "Strassen Result Matrix:" << endl; 
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << matD[i][j] << " ";
		} cout << endl;
	}

	// End program
	return 0;
}
