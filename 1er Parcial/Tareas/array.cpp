#include <iostream>

using namespace std;

int main() {

	int n = 4;
	int Arr1[n] = {1, 2, 3, 4};
	int Arr2[n][n];
	bool validator = true;
	int acum = 0;
	int count = 1;

	// cout << "01 03 06 10" << endl;
	// cout << "03 02 05 09" << endl;
	// cout << "06 05 03 07" << endl;
	// cout << "10 09 07 04" << endl << endl;

	for (int i=0; i<n; i++) {
		acum+=Arr1[i];
		Arr2[0][i] = acum;
	}

	for (int i=1; i<n; i++) {

		acum = 0;
		validator = true;
		Arr2[i][0] = Arr2[0][i];

		for (int j=1; j<n; j++) {
			
			if (validator) {
				if (i == j) {
					validator = false;
					Arr2[i][j] = Arr1[count];
					count++;
					acum = Arr2[i][j];
				} else {
					Arr2[i][j] = Arr2[j][i];  
				}
			} else {
				acum += Arr1[j];
				Arr2[i][j] = acum;
			}
		}
	}

	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<n; j++) {
	// 		cout << Arr2[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return 0;
}
