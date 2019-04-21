/*
Description:
Dado n (número de nodos), se desea saber cuantos árboles binarios se pueden formar con ellos.



Input:

LLega en una línea n ( 1 <= n <= 30), cantidad de nodos

Output:

En una línea con la cantidad de arboles binarios

Sample Input:
3
Sample Output:
5 BTrees
*/
#include <iostream>
#include <iomanip>

using namespace std;

double factorial(double n) {

	double res = 1;
	for (int i=1; i<=n; i++) {
		res*=i;	
	}

	return res;
}

double howManyTrees(double n) {

	double doubleN = 2*n;
	double up = factorial(doubleN);
	double down = factorial(n+1)*factorial(n);
	
	// cout << up << endl;
	// cout << down << endl << endl;

	int result = (up / down);

	return result;
}

int main() {

	double n = 19;

	cin >> n;	

	cout << fixed;
	cout << setprecision(0) << howManyTrees(n) << " BTrees" << endl;

	// Termina programa
	return 0;
}