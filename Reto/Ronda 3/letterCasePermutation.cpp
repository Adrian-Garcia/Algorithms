/*
Letter Case Permutation
Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void combinations (string S, int i, vector<string> &v) {

	string aux;
	char c = S[i];

	c = (islower(c)) ? 
		toupper(c) : tolower(c);  

	S[i] = c;	

	v.push_back(S);

	for (int j=0; j<v.size(); j++) {
		aux = v[j].substr(0,i);
		aux.insert(i+1, S.substr(i+1, S.length()-1));
	}
}

int main() {

	string S = "aaa";

	/*
	S = aaa;
	v = 
	aaa 0
	Aaa 1
	aAa 2
	AAa 3
	aaA 4
	AaA 5
	aAA 6
	AAA 7
	*/

	//--------------------------------------------------------------------

	std::vector<string> v;

	v.push_back(S);
	
	int i=0;
	while (S[i]) {
		if (isalpha(S[i]))
			combinations(S, i, v);
		i++;
	}

	//return v;
	//--------------------------------------------------------------------

	for (int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}
