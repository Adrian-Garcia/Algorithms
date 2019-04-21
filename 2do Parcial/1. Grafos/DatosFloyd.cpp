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
*/
#include <iostream>
#include <math.h>

using namespace std;

//Function floyd
void floyd(int D[20][20], int n) {

	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][k]+D[k][j] < D[i][j]) {
					D[i][j] = D[i][k]+D[k][j];
				}
			}
		}
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

	floyd(D,n);

	for (int i=0; i<q; i++) {
		cin >> a >> b;
		cout << D[a-1][b-1] << endl;
	}

	return 0;
}
