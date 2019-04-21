/*
689. Maximum Sum of 3 Non-Overlapping Subarrays

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.
Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.
Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
	
	Input: [1,2,1,2,6,7,5,1], 2
	Output: [0, 3, 5]
	
	Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5]. 
	We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Note:
	nums.length will be between 1 and 20000.
	nums[i] will be between 1 and 65535.
	k will be between 1 and floor(nums.length / 3).
*/
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void divide(vector<int> &res, int k, int low, int high) {	

	if (high - low < k) {

		for (int i=0; i<n; i++) {

		}
	} 

	else {

		for (int i=(high-low)/2; i<k-1; i++) {			//Corregir i
			for (int j=i; j<k; j++) {
				if () 

			}
		}
	}
}

int main() {

	std::vector<int> nums;
	int k = 2;

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(1);
	
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << endl;
	}	

//-----------------------------------------------------------------------------------------------

	std::vector<int> res(3, INT_MIN);

	divide(res, k, low, high, max);

//-----------------------------------------------------------------------------------------------

	for (int i=0; i<res.size(); i++) {
		cout << res[i] << endl;
	}

	return 0;
}