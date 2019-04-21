#include <iostream>
#include <string>

using namespace std;

bool flag (string courses[100][100], int n, int required[100]) {
	
	string curr;

	for (int i=0; i<n; i++) {
		
		for (int j=1; j<required[i]-1; j++) {
			curr = courses[i][j];

			for (int k=0; k<n; k++) {
				
				if (courses[][]) {
					
				}
			}
		}
	}
	
	return true;
}

int main() {

	int n, m;
	string a, b;
	string courses[100][100] = {"A"};
	int required[100] = {1};

	cin >> n >> m;


	for (int i=0; i<n; i++) {
		cin >> courses[i][0];
	}

	for (int i=0; i<m; i++) {
		
		cin >> a >> b;

		for (int j=0; j<n; j++) {
			
			if (courses[j][0] == a) {
				courses[j][required[j]] = b;
				required[j]++;
			}
		}
	}

	if (flag(courses, n, required)) {
		cout << "CORRECT" << endl;
	} else{
		cout << "INCORRECT" << endl;
	}

	return 0;
}
