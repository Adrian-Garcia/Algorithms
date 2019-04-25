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
#include <queue>
#include <vector>

using namespace std;

int kombat(int n, int k, int damage[], string buttons) {

	int res = 0;
	int counter = 0;
	char last = '@';
	priority_queue<int, vector<int>, greater<int> > hits;

	for (int i=0; i<n; i++) {
		
		// Diferent letter
		if (buttons[i] != last) {
			
			last = buttons[i];
			counter = 0;
			
			// Add previous hits
			while (!hits.empty()) {
				res += hits.top();
				hits.pop();
			}

			// add that leter to the queue
			hits.push(damage[i]);
		}

		// Same letter, less repetitive than k
		else if (counter < k) {
			
			// Added to the sum hits
			hits.push(damage[i]);
			counter++;
		}

		// Same letter, appear more than k
		else {

			// Added to hits if the current value is bigger than the las one
			if (hits.top() < damage[i]) {
				hits.pop();
				hits.push(damage[i]);
			}
			counter++;
		}
	}
	
	// Add last hits
	while (!hits.empty()) {
		res += hits.top();
		hits.pop();
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

	// cin >> buttons;
		
	cout << kombat(n, k, damage, buttons) << endl;

	// End program
	return 0;
}
