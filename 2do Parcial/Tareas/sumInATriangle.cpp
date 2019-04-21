/*
Description:
	Let us consider a triangle of numbers in which a number appears in the first line, two numbers appear in the second line, etc.
	Develop a program which will compute the largest of the sums of numbers that appear on the paths starting from the top towards the base, so that: 
	On each path the next number is located on the row below, more precisely either directly below or below and one place to the right.
	The number of rows is strictly positive, but less than 11 and all numbers are integers between 0 and 99.

Input
	In the first line integer comes  n (the number of test cases, no more than 20). Then n test cases follow, where each test case starts with the number of 
	lines which is followed by their content.

Output
	For each test case write the result of each case in a separate line.

Sample Input:
	2
	3
	1
	2 1
	1 2 3
	4
	1
	1 2
	4 1 2
	2 3 1 1

Sample Output:
	5
	9
*/
#include <iostream>

using namespace std;

// Funcion que suma el mayor trabajo en un triangulo 
int sumInATriangle (int mat[12][12], int n) {

	// Valor de retorno
	int res = -1;
	
	// Llenamos la columna izquieda
	for (int i=1; i<n; i++) {
		mat[i][0] = mat[i][0] + mat[i-1][0]; 
	}

	// Llenamos la diagonal
	for (int i=1; i<n; i++) {
		mat[i][i] = mat[i][i] + mat[i-1][i-1]; 
	}

	// Solo calculamos si el tamanio del triangulo es mayor a 2
	if (n>2) {		
		
		// Calcula triangulo interno	
		for (int i=2; i<n; i++) {

			for (int j=1; j<i; j++) {

				mat[i][j] += max(mat[i-1][j-1], mat[i-1][j]);
			}
		}
	}

	//Buscamos el mas grande del ultimo nivel
	for (int i=0; i<n; i++) {
		res = (mat[n-1][i] > res) ? mat[n-1][i] : res;
	}

	// Regresamos el resultado 
	return res;
}

// Despliega mat, funcion de debugeo, no se usa en el programa final
void print (int mat[12][12], int n) {

	for (int j=0; j<n; j++) {
		
		for (int k=0; k<j+1; k++) {goo

			cout << mat[j][k] << " ";
		} 	cout << endl;
	}

	cout << endl << endl;
}

int main() {

	int t;	// Numero de triangulos
	int n; 	// Tamanio del triangulo

	cin >> t;	// Numero de triangulos
	for (int i=0; i<t; i++) {

		cin >> n;			// Pedimos tamanio de triangulo
		int mat[12][12];	// Matriz con el triangulo

		// Pedimos matiz del triangulo
		for (int j=0; j<n; j++) {
			for (int k=0; k<j+1; k++) {
				cin >> mat[j][k];
			}
		}

		// Desplegamos resultado de la suma mas grande
		cout << sumInATriangle(mat, n) << endl;
	}

	// Terminamos programa
	return 0;
}