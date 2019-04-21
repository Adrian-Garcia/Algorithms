#include <iostream>
#include <limits.h>

using namespace std;

int minimum(int ci[], int l, int n) {

	int Matrix[50][50];

	for (int i=1; i<=n; i++) {

		for (int j=i-1; j>=0; j--) {

			if (j+1 == i) 
				Matrix[j][i] = 0;

			else {

				Matrix[j][i] = INT_MAX;

				for (int k=j+1; k<i; k++) {

					if (Matrix[j][k]+Matrix[k][i] < Matrix[j][i])
						Matrix[j][i] = Matrix[j][k]+Matrix[k][i];
				}

				Matrix[j][i] += ci[i] - ci[j];
			}
		}
	}

	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<n; j++) {
	// 		cout << Matrix[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }

	//Regresamos valor
	return Matrix[0][n];
}

int main() {

	int l;				//Longitud
	int n;				//Numero de cortes

	//Pedimos longitud
	cin >> l;			

	while (l != 0) {

		//Pedimos numero de cortes		
		cin >> n;

		int ci[100]; //Lugares donde se deben realizar los cortes

		//Pedimos lugares de corte
		for (int i=1; i<=n; i++) {
			cin >> ci[i];
		}

		ci[0] = 0;
		n++;
		ci[n] = l;

		//Desplegamos valor minimo
		cout << "The minimum cutting is " << minimum(ci, l, n) <<".\n";
		cin >> l;
	}

	//Terminamos programa
	return 0;
}
