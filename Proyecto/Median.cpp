/*
Teniendo un conjunto de 2n datos enteros que fueron separados en dos arreglos de tamaño n, y posteriormente cada arreglo 
fue ordenado ascendentemente, y sabiendo que no existen valores repetidos en los 2n valores. Se desea encontrar la mediana 
del conjunto de 2n datos. La mediana de un grupo de datos, es aquel dato que tiene el 50% de los datos menores a él y el 
50% de los datos mayores a él.

Utiliza la estrategia de divide y vencerás, para diseñar un algoritmo que calcule la mediana de los 2n datos incluidos en 
los dos arreglos (1 <= n <= 100). El algoritmo que obtengas, deberá tener un orden logarítmico base 2 o mejor, O(log2 n).

Input:
	Primero vendrá t el número de casos, por cada caso vendrá el número de datos por arreglo (n) y cada uno de los n datos 
	del arreglo 1 y posterior cada uno de los n datos del arreglo 2. Los datos de los arreglos son enteros positivos no 
	mayores a 4.

Output:
	Por cada caso vendrá un número flotante con dos decimales representando la mediana del total de 2n datos con el formato 
	de presentación del ejemplo de salida.

Sample Input:
	2
	5
	1
	4
	7
	8
	10
	2
	9
	11
	14
	15
	3
	2
	4
	5
	1
	3
	6

Sample Output:
	Median case 1: 8.50
	Median case 2: 3.50
*/
#include <iostream>

using namespace std;

double median(int array1[], int array2[], int n) {

	// Resultado final
	int res;

	// Indices
	int min = 0;
	int max = n;

	// Busqueda Binaria
	while (min <= max) {
	
		int i = (max + min) / 2; 
		int j = (2*n+1)/2 - i;
		
		if (i<n &&) {

		}

	}

	// Regresamos media
	return res;

}

int main() {

	int cases = 1;
	int n = 5;

	cin >> cases;

	for (int j=0; j<cases; j++) {
		
		cin >> n;

		int array1[n];
		int array2[n];

		for (int i=0; i<n; i++) {
			cin >> array1[i];
		}

		for (int i=0; i<n; i++) {
			cin >> array2[i];
		}

		cout << "Median case " << j+1 << ": " << median(array1, array2, n) << endl;
	}

	// Termina programa
	return 0;
}
