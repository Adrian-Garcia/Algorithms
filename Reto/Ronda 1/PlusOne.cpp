/*
Plus One

Given a non-empty array of digits representing a non-negative integer, plus
one to the integer.

The digits are stored such that the most significant digit is at the head 
of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the 
number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

#include <iostream>
#include <vector>		//Para vectores

using namespace std;

int main() {
        
	vector<int> digits(3,9);

    int size = digits.size();
    
    int i;
    
    for(i=size-1; i>=0; i--){
     
        if(digits[i]<9){
            digits[i]++;
            break;
        }
     
        else {
            digits[i]=0;
        }
    }

    if(i==-1){
        digits.insert(digits.begin(), 1);
    }

    for (int i=0; i<size; i++) {
    	cout << digits[i] << " ";
    }
    
	return 0;
}
