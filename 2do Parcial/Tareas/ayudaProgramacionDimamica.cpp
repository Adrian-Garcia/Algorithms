/*

Algoritmo de Floyd

	Grafo no-dirigido y ponderado

		1º Línea. n m q
			n - Cantidad de Nodos
			m - Cantidad de Arcos
			q - Cantidad de Queries

		m Líneas con a b c
			Arco de (a,b) y (b,a) con un costo de c

		q Líneas con a b
			Arco (a,b) del cual se desea conocer su costo mínimo

	datosFloyd.txt
		10 20 3
		1 2 7
		1 4 8
		1 7 14
		2 5 9
		2 6 4
		3 4 4
		3 7 10
		3 8 1
		4 5 5
		4 6 10
		4 8 14
		5 9 15
		6 7 17
		6 8 2
		6 10 3
		7 8 15
		7 10 8
		8 9 9
		8 10 4
		9 10 1
		10 1
		8 4
		5 7

*/
#include <iostream>
#include <math.h>

using namespace std;

//Function floyd
void floyd(int D[20][20], int n) {
	
	cout << endl << endl;

	for (int k=0; k<n; k++) {

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][k]+D[k][j] < D[i][j]) {
					D[i][j] = D[i][k]+D[k][j];
				}
			}
		}

		//Desplegamos datos
		cout << "D" << k+1  << endl;
		for (int a=0; a<n; a++) {
			for (int b=0; b<n; b++) {
				
				if (D[a][b] != INT_MAX) {
					cout << D[a][b] << "\t";	
				}
				
				else {
					cout << "INF" << "\t";
				}
				
			}
			cout << endl;
		} 
		
		cout << endl;
	}
}

int main() {

	int n, m, q, a, b, c;


	cin >> n >> m >> q;

	int D[20][20];

	for (int i=0; i<n; i++) {

		//Diagonal igualada a 0
		D[i][i] = 0;
		
		for (int j=i+1; j<n; j++) {
			D[i][j] = D[j][i] = INT_MAX;
		}
	}
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		D[a-1][b-1] = D[b-1][a-1] = c;
	}
	
	//Desplegamos datos
	cout << endl << "D0" << endl;
	for (int a=0; a<n; a++) {
		for (int b=0; b<n; b++) {
			
			if (D[a][b] != INT_MAX) {
				cout << D[a][b] << "\t";	
			}
			
			else {
				cout << "INF" << "\t";
			}
			
		}
		cout << endl;
	}

	floyd(D,n);

	for (int i=0; i<q; i++) {
		cin >> a >> b;
		cout << D[a-1][b-1] << endl;
	}

	return 0;
}
