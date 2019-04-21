#include <iostream>
#include <vector>

using namespace std;

int main() {

	std::vector<int> nums;

	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);

	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}

	//---------------------------------------------------------

	int first = nums[0];
	int second = first;
	int third = second; 


	// 1 3 2 2 
	// first 	3
	// second 	1
	// third 	1

	for (int i=0; i<nums.size(); i++) {
		if (first < nums[i]) {
			third = second;
			second = first;
			first = nums[i];
		}
		else {
			
		}
	}

	//---------------------------------------------------------
	cout << endl << third << endl;

	return 0;
}