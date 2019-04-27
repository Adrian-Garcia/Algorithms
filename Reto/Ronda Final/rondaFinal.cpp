/*
10 3 10
1
5
8
1 2 10
1 6 3
2 3 2
2 4 7
5 6 2
5 7 9
7 4 1
8 9 6
9 7 9
9 10 11
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int k;		// Cantidad de Empleados
int n;		// Equipos trabajando
int m; 		// Cantidad de relaciones

struct punto{
	int x, y;

	//Es necesario sobrecargar el operador para ponerlo en priority queue
	bool operator< (const punto &otro) const {
		if (y == otro.y) {
			return x < otro.x;	
		}
		return y > otro.y;
	}
};

void pesos(int mat[10000][10000], int jefes[100][2]) {

	int currJefe;
	queue<int> empleados;

	for (int a=0; a<n; a++) {
		
		currJefe = jefes[a][0];
		empleados.push(currJefe);

		while (!empleados.empty()) {
			
			// Ver empleados
			for (int i=0; i<k+1; i++) {
				
				// Si es jefe de ese empleado
				if (mat[empleados.front()][i] != 0) {
					empleados.push(i);
					jefes[a][1] += mat[empleados.front()][i];
				}
			}
			empleados.pop();
		}
	}
	
	// priority_queue<punto, vector<punto>, greater<punto> > pq;
	priority_queue<punto> pq;
	stack<punto> s;

	punto aux;
	for (int i=0; i<n; i++) {
		aux.x = jefes[i][0];
		aux.y = jefes[i][1];
		pq.push(aux);
	}

	while (!pq.empty()) {
		aux = pq.top();
		s.push(aux);
		pq.pop();
	}

	while (!s.empty()) {
		aux = s.top();
		cout << aux.x << " " << aux.y << endl;
		s.pop();
	}
}

void despliegaMat(int k, int mat[20][20]) {
	
	for (int i=1; i<k; i++) {
		for (int j=1; j<k; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {

	int a, b;	// Indices
	int val;	// Valor de la posicion

	cin >> k;	// Empleados
	cin >> n; 	// Jefes
	cin >> m;	// Relaciones

	int jefes[100][2];
	int mat[10000][10000] = {0};

	for (int i=0; i<n; i++) {
		cin >> jefes[i][0];
		jefes[i][1] = 0;
	}

	for (int j=0; j<m; j++) {
		cin >> a >> b >> val;
		mat[a][b] = val;
	}
	
//	cout << endl;
//	despliegaMat(k, mat);

	pesos(mat, jefes);

	return 0;
}
