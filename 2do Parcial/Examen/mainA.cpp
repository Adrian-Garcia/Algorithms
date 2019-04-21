#include <iostream>
// El Tesoro de la Tortuga
// Matricula:	A01351166
// Nombre: 		Adrián García López

using namespace std;
#define MAX 100

int turtle(int mat[MAX][MAX], int n, int m){

	// Primera Fila
	for (int i=1; i<n; i++) {
		mat[i][0]+=mat[i-1][0];
	}

	// Primera Columna
	for (int i=1; i<m; i++) {
		mat[0][i]+=mat[0][i-1];
	}

	// Hacemos cuadrado interno
	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			mat[i][j] += max(mat[i-1][j], mat[i][j-1]);
		}
	}
	
	// Regresamos ultimo valor de la matriz
	return mat[n-1][m-1];
}

void print(int mat[MAX][MAX], int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << mat[i][j]<< " ";
		}
		cout << endl;
	}	
}

int main(){
	
	int n, m;
	int mat[MAX][MAX];
	cin >> n  >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}

//	print(mat, n, m);
	cout << turtle(mat, n, m)<<endl;
	
	return 0;
}
