#include <iostream>

using namespace std;

int damage() {

	int res;

	return res;
}

int main() {

	int n = 7;			// Length of hit button sequence
	int k = 3;			// Max num imputs
	string buttons;		// Button Sequence
	buttons = "baaaaca";

	// cin >> n >> k;

	int damage[n];

	// for (int i=0; i<n; i++) {
	// 	cin >> damage[i];
	// }

	// cin >> buttons;

	cout << damage(n, k, damage, buttons);

	// End program
	return 0;
}