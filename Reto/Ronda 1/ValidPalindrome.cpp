/*
Given a string, determine if it is a palindrome, considering only 
alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid 
palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
*/

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

int main() {

//	string phrase = "A man, a plan, a canal: Panama";
	string s = "Sex at noon taxes.";

	int i=0;
	int j=s.size()-1;

	while (i != j) {
		
		while (tolower(s[i]) < 'a' || tolower(s[i]) > 'z') {
			i++;

			if (i == j && tolower(s[i]) == tolower(s[j])) {
				cout << "true";
				return 0;
			}

			else if (i == j && tolower(s[i]) != tolower(s[j])) {
				cout << "false";
				return 0;
			}
		}

		while (tolower(s[j]) < 'a' || tolower(s[j]) > 'z') {
			j--;

			if (i == j && tolower(s[i]) == tolower(s[j])) {
				cout << "true";
				return 0;
			}

			else if (i == j && tolower(s[i]) != tolower(s[j])) {
				cout << "false";
				return 0;
			}
		}

		if (tolower(s[i]) != tolower(s[j])) {
			cout << "false";
			return 0;
		}

		i++;
		j--;
	}

	cout << "true";
	return 0;
}
