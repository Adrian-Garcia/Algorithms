/*
Description:
The beagles in BeagleTown love to play BeagleKombat, which has 26 buttons (from ‘a’ to ‘z’). The game consists in making 
the more damage possible clicking buttons but is not possible to push the same button more than k times continues.
Having a hit button sequence and their damage per each one, compute the maximum damage that any beagle could make with 
this.

Input
	In the first line comes n - the length of the hit button sequence and k – the maximum times hit the same button in 
	continues way (1<=k<=n<=2*10⁵)
	In the second line comes the damage of each button (1<=a[i]<=10⁹)
	In the third line comes a string with n letters meaning the button sequence hit.

Output
	An integer meaning the maximum possible damage of the game.

Sample Input:
	7 3
	1 5 16 18 7 2 10
	baaaaca

Sample Output:
	54
*/
#include <iostream>
#include <string>

using namespace std;

int kombat(int n, int k, int damage[], string buttons) {

	int res = 0;
	int counter = 0;
	char last = '@';

	for (int i=0; i<n; i++) {
		
		// Cambio de letra
		if (buttons[i] != last) {
			last = buttons[i];
			counter = 0;
			res += damage[i];
		}

		else if (counter < k) {
			counter++;
			res += damage[i];
		}

		else {
			counter++;
		}
	}
	
	return res;
}

int main() {

	int n = 7;				// Length of hit button sequence
	int k = 3;				// Max num imputs
	string buttons;			// Button Sequence
	buttons = "baaaaca";

	// cin >> n >> k;

	int damage[n] = {1, 5, 16, 18, 7, 2, 10};

	// for (int i=0; i<n; i++) {
	// 	cin >> damage[i];
	// }

//	cin >> buttons;
		
	cout << kombat(n, k, damage, buttons) << endl;

	// End program
	return 0;
}
