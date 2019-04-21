#include <iostream>
#include <string>

using namespace std;

int main() {

	string a;
	int central, mitad;

	//Pedimos el input
	cin >> a;

	//Actualizamos el tamanio de las mitades y el valor central
	mitad = a.size()/2;
	central = mitad;

	//Mientras no encontremos el unico caracter, el codigo se repite
	while (a[central] == a[central-1] || a[central] == a[central+1]) {
		
		//El caracter igual se encuentra a la izquierda
		if (a[central] == a[central-1]) {

			//La mitad es impar
			if (mitad%2 == 1) {

				//El valor central va a la derecha
				central += mitad/2+1;
				mitad = mitad/2;
			}

			//La mitad es par
			else {

				//El valor central va a la izquierda
				central -= mitad/2;
				mitad = mitad/2;
			}
		}

		//El caracter igual se encuentra a la derecha
		else {


			//La mitad es impar
			if (mitad%2 == 1) {

				//El valor central va a la izquierda
				central -= mitad/2+1;
				mitad = mitad/2;
			}

			//La mitad es par
			else {

				//El valor central va a a derecha
				central += mitad/2;
				mitad = mitad/2;
			}
		}
	}

	//Desplegamos valor
	cout << a[central] << endl;

	//Terminamos programa
	return 0;
}