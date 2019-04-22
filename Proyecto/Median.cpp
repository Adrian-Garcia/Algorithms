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

int median(int array1[], int array2[], int n) {

	int a, b;
	int index1 = 0;
	int index2 = 0;
	bool flag = true;

	for (int i=0; i<=n && flag; i++) {
		
		if (index1 == n) {
			a = b;
			b = array2[0];
			flag = false;
		}

		else if (index2 == n) {
			a = b;
			b = array1[0];
			flag = false;
		}

		if (flag && array1[index1] < array2[index2]) {
			a = b;
			b = array1[i];
			index1++;
		}

		else if (flag && array1[index1] > array2[index2]) {
			a = b;
			b = array2[i];
			index2++;
		}
	}

	// Regresamos media
	return (a+b)/2;

}

int main() {

	int cases = 1;
	int n = 5;

	for (int j=0; j<cases; j++) {
		
		// cin >> n;

		int array1[n];
		int array2[n];

		for (int i=0; i<n; i++) {
			cin >> array1[i];
		}

		for (int i=0; i<n; i++) {
			cin >> array2[i];
		}

		cout << "Median case " << j+1 << "1: " << median(array1, array2, n) << endl;
	}

	// Termina programa
	return 0;
}