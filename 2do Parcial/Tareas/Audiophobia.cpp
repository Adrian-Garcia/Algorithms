#include <iostream>
#include <limits.h>

using namespace std;

//Funcion floyd
void floyd (int D[100][100], int c) {

	for (int k=0; k<c; k++) {
		for (int i=0; i<c; i++) {
			for (int j=0; j<c; j++) {z
				if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > max(D[i][k],D[k][j])){
					D[i][j] = max(D[i][k],D[k][j]); 
				}
			}
		}
	}
}

int main() {

	int cases; 			//Casos 
	int c;		 		//Cruces
	int s;				//Numero de calles
	int q; 				//Numero de consultas
	int c1;				//Cruce 1
	int c2; 			//Cruce 2
	int d; 				//Decibeles

	cin >> cases; 

	for (int a=0; a<cases; a++) {

		cin >> c >> s >> q;

		//Matriz con los datos (Maximo 100)
		int D[100][100];

		for (int i=0; i<c; i++) {

			//Diagonal igualada a 0
			D[i][i] = 0;

			//Todos los demás valores serán infinito
			for (int j =i+1; j<c; j++) {
				D[i][j] = D[j][i] = INT_MAX;
			}
		}

		for (int i=0; i<s; i++) {
			cin >> c1 >> c2 >> d;
			D[c1-1][c2-1] = D[c2-1][c1-1] = d;
		}

		//Buscamos los valores por cada camino
		floyd(D,c);

		//Desplegamos valores
		cout << "Case " << a+1 << ":\n";
		for (int i=0; i<q; i++) {
			
			cin >> c1 >> c2;
			
			if (D[c1-1][c2-1] < INT_MAX) 
				cout << D[c1-1][c2-1] << endl;
			else 
				cout << "no path" << endl;
		}
	}

	//Terminar programa
	return 0;
}