#include <iostream>
#include <string>

using namespace std;

int main() {

	int n;
	int arr[2];
	string usr;

	arr[0] = 0;
	arr[1] = 0;

	cin >> n;
	cin >> usr;

	for (int i=0; i<n; i++) {
		(usr[i] == '0') ? arr[0]++ : arr[1]++;
	}

	(arr[1] > arr[0]) ?
		cout << arr[1]-arr[0] << endl : cout << arr[0]-arr[1] << endl;

	return 0;
}
