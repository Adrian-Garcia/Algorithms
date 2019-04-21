/*
Description:
	En BeagleTown existe un juego donde un grupo de BeaglesBalls son lanzadas a un grupo de soldados. Primeramente se colocan los soldados en linea, cada uno 
	de los cuales tiene un nivel de fortaleza, en otro lado se tienen un grupo de BeaglesBalls las cuasles son lanzadas a los soldados, cada BeaglesBall tiene 
	un poder de derribar soldados dependiendo del poder de la BeagleBall y de la fortaleza de los soldados. Cada soldado es derribado en orden que esta 
	alineado y cuando todos son derribados son vueltos a parara y continuan con la siguiente BeagleBall.

	Por ejemplo si existen 5 soladados con la siguiente fortaleza 3 2 5 1 2 y existen 4 BeagleBalls con el siguiente poder 5 1 10 3. La primer BeagleBall 
	derriba los solados 1 y 2, La siguiente BeealgBall reduce la fortaleza en 1 del soldado 3, la BeagleBall derriba los soldados 3, 4 y 5, entonces se vuelven 
	a levantar los soldados y la cuarta BeagleBall derriba al soldado 1.

	Se desea saber el n?mero de soldados que permanecen de pie despu? de cada BeagleBall. En el ejemplo de arriba ser?n 3 3 5 4.

Input
	Primero llega n - numero de soldados y q - n?mero de BeaglesBalls (1 <= n, q <= 200000), entonces llega una linea con n enteros (0 < a[i] <= 10?) 
	significando la fortaleza de cada soldado, luego llega una linea con q enteros (0 < b[i] <= 10?) significando el poder de cada BeagleBall.

Output
	Imprima q lineas, cada una con el entero del n?mero de soldados despu? de lanzar cada BeagleBall.

Sample Input:
	5 5
	1 2 1 2 1
	3 10 1 1 1

Sample Output:
	3
	5
	4
	4
	3
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;	// Soldiers
int q;	// Beagle Balls

// function that delete soldiers from array
void delSoldiers(int &rest, int soldiers[200000], int &index, int &alive) {
	
	if (alive > 0) {
		
		soldiers[index] -= rest;

		if (soldiers[index] < 0) {
			alive--;
			rest = abs(soldiers[index]);
			index++;
			delSoldiers(rest, soldiers, index, alive);
		}

		else if (soldiers[index] == 0) {
			alive--;
			index++;
			
			if (alive > 0) {
				cout << alive << endl;
			}
		}
		
		else {
			cout << alive << endl;
		}
	}
}

int main() {

	cin >> n >> q;

	int soldiers[n]; 		// to store soldiers values
	int soldiersAux[n];		// to store auxiliar values for soldiers
	int beagleBalls[q];		// to store beagleBalls values
	int index = 0;			// to store soldier index
	int alive = n;			// to store num of alive soldiers
	int rest;				// to store rest value

	// get soldier values
	for (int i=0; i<n; i++) {
		cin >> soldiers[i];
		soldiersAux[i] = soldiers[i];
	}
	
	// get beagleBalls values
	for (int i=0; i<q; i++) {
		cin >> beagleBalls[i];
	}

	for (int i=0; i<q; i++) {

		rest = beagleBalls[i];
		delSoldiers(rest, soldiers, index, alive);

		if (alive <= 0) {

			memcpy(soldiers, soldiersAux, sizeof(soldiers));
			alive = n;
			index = 0;
			cout << alive << endl;
		}
	}

	// end program
	return 0;
}
