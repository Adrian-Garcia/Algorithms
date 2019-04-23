#include <iostream>

using namespace std;

bool sort(int train1[], int train2[], int order[]) {
	
	bool flag = true;

	// Size of each train
	int N1 = sizeof(train1) / sizeof(int);
	int N2 = sizeof(train2) / sizeof(int);

	for (int i=0; i<n && flag; i++) {
		
	}

	return flag;
}

int main() {

	int cases; 			// Casos
	int N1, N2;			// Numero de vagones

	cin >> N1 >> N2;

	while (!N1 && !N2)	{

		int train1[N1];
		int train2[N2];
		int order[N1+N2];

		// Ask for train i
		for (int i=0; i<N1; i++) {
			cin >> train1[i];
		}

		// Ask for train 2
		for (int i=0; i<N2; i++) {
			cin >> train2[i];
		}

		// Ask for order
		for (int i=0; i<N1+N2; i++) {
			cin >> order[i];
		}

		sort(train1, train2, order) ? 
			cout << "YES" << endl:
			cout << "NO" << endl;

		// Ask new size of trains
		cin >> N1 >> N2;
	}	



	// End program
	return 0;
}