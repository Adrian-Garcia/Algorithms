/*
921. Minimum Add to Make Parentheses Valid

Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

 

Example 1:
	Input: "())"
	Output: 1

Example 2:
	Input: "((("
	Output: 3

Example 3:
	Input: "()"
	Output: 0

Example 4:
	Input: "()))(("
	Output: 4

Note:
	S.length <= 1000
	S only consists of '(' and ')' characters.
*/
#include <iostream>
#include <string>

using namespace std;

int minAddToMakeValid(string S) {

	int i;
	int left = 0;
	int min = 0;

	//())
	// left 	0
	// min 		1

	for (i=0; i<S.length(); i++) {

		if (left == 0 && S[i] == ')') 
			min++;

		else if (S[i] == '(') 
			left++;

		else if (S[i] == ')') 
			left--;

		else if (left == 0  && S[i] == '(')
			min++;
	}

	return min+left;
}

int main() {

	string s = "))(())";

	// izq 0
	// min 2

	cout << minAddToMakeValid(s) << endl;
 
	return 0;
}