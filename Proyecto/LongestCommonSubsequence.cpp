/*
Description:
	El problema de la subsecuencia com?n mas grande (LCS) es el problema de encontrar la secuencia comun mas grande de todas las secuencias en un conjunto de 
	secuencias (normalmente 2 secuencias). Para este problema no se requieren posiciones consecutivas dentro de la secuencia original. Por ejemplo, teniendo 
	los strings "AAAAAAABBAAB" y "ABAABBAB", la secuencia comun mas grande es el string "AAABBAB" con una longitud de 7.

Input:
	La entrada consiste en un numero de casos. Por cada caso llegar? 2 strings (0 < longitud1, longitud2 <=1000).

Output:
	Por cada caso, despliega en una linea la longitud de la secuencia mas grande (LCS). Revisa la presentaci? en el Ejemplo de Salida.

Sample Input:
	2
	AAAAAAABBAAB
	ABAABBAB
	XMJYAUZ
	MZJAWXU

Sample Output:
	Case 1: 7
	Case 2: 4
*/

#include <iostream>
#include <string>

using namespace std;

int findLCS(string a, string b) {

	// Tamanios de strings
	int aSize = a.length();
	int bSize = b.length();

	// Un espacio mas para aniadir 0s en primera fila y columna
	int Mat[aSize+1][bSize+1];

	// Primera fila
	for (int i=0; i<=aSize; i++) {
		Mat[i][0] = 0;
	}

	// Primera columna
	for (int i=0; i<=bSize; i++) {
		Mat[0][i] = 0;
	}

	// Matriz interna
	for (int i=1; i<=aSize; i++) {
		
		for (int j=1; j<=bSize; j++) {
			
			if (a[i-1] == b[j-1])
				Mat[i][j] = Mat[i-1][j-1]+1;

			else 
				Mat[i][j] = max(Mat[i][j-1], Mat[i-1][j]);
		}
	}

	// Regresamos ultimo valor de la matriz
	return Mat[aSize][bSize];
}

int main() {

	string a;
	string b;

	int cases;
	int res;
	int aSize;
	int bSize;

	cin >> cases;

	for (int i=0; i<cases; i++) {

		cin >> a >> b;

		res = findLCS(a, b);

		cout << "Case " << i+1 << ": " << res << endl;
	}

	// end program
	return 0;
}