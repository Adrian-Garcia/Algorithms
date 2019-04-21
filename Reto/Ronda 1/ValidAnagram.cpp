/*
Valid Anagram
Given two strings s and t , write a function to determine if t is an 
anagram of s.

Example 1:
	Input: s = "anagram", t = "nagaram"
	Output: true

Example 2:
	Input: s = "rat", t = "car"
	Output: false

Note:
	You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your 
solution to such case?	
*/

#include <iostream>
#include <map>

using namespace std;

int main() {

	string s = "hola"; 
	string t = "ohsa";

	if (s.size() != t.size()) {
		cout << "false";
		return 0;
	}

	map<char, int> sMap;
	map<char, int> tMap;

	map<char, int>::iterator it;
	map<char, int>::iterator is;

	int aux;

	for (int i=0; i<s.size(); i++) {

		//Buscamos el numero
		it = sMap.find(s[i]);

		//Encontramos el numero
		if (it != sMap.end()) {
			aux = it->second+1;	
			sMap.erase(it);
			sMap.insert(pair <char, int> (s[i], aux));
		}

		//No encontramos el numero
		else {
			sMap.insert(pair <char, int> (s[i], 0));
		}
	}

	for (int i=0; i<t.size(); i++) {

		//Buscamos el numero
		it = tMap.find(t[i]);

		//Encontramos el numero
		if (it != tMap.end()) {
			aux = it->second+1;	
			tMap.erase(it);
			tMap.insert(pair <char, int> (t[i], aux));
		}

		//No encontramos el numero
		else {
			tMap.insert(pair <char, int> (t[i], 0));
		}
	}

	for (it=tMap.begin(); it!=tMap.end(); ++it) {

		is = sMap.find(it->first);

		if (is != sMap.end()) {
			if (it->second != is->second) {
				cout << "false";
				return 0;
			}
		}

		else {
			cout << "false";
			return 0;
		}
	}

	cout << "true";
	return 0;
}
