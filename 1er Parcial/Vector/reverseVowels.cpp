#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>

using namespace std;

int main() {

	string s = "hello";

	cout << s << endl;

	//-----------------------------------------------

	stack<char> vowels;
	string t = s;

	for (int i=0; i<t.size(); i++) {
		if (tolower(t[i]) == 'a' || tolower(t[i]) == 'e' || 
			tolower(t[i]) == 'i' || tolower(t[i]) == 'o' || 
			tolower(t[i]) == 'u')
			vowels.push(t[i]);
	}

	for (int i=0; i<t.size(); i++) {
		if (tolower(t[i]) == 'a' || tolower(t[i]) == 'e' || 
			tolower(t[i]) == 'i' || tolower(t[i]) == 'o' || 
			tolower(t[i]) == 'u') {
			t[i] = vowels.top();
			vowels.pop();
		}
	}

	// return t;

	//----------------------------------------------
	cout << t << endl;

	return 0;
}