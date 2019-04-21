#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	std::vector<int> nums;

	// Input: [1,1,1,3,3,2,2,2]
	// Output: [1,2]

	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(2);

	for (int i=0; i<nums.size(); i++) 
		cout << nums[i] << " ";

	//-------------------

	std::vector<int> myVector;
	map<int, int> myMap;
	map<int, int>::iterator it;
	int i, n;

	for (i=0; i<nums.size(); i++) {
		it = myMap.find(nums[i]);

		if (it != myMap.end()) {
			it->second++;
		} else {
			pair <int, int> myPair(nums[i], 1);
			myMap.insert(myPair);
		}
	}

	n = nums.size()/3;

	for (it=myMap.begin(); it!=myMap.end(); ++it) {
		if (it->second > n) {
			myVector.push_back(it->first);
		}
	}

	//return myVector

	//-----------------


	cout << endl << endl;
	for (i=0; i<myVector.size(); i++) 
		cout << myVector[i] << " ";

	return 0;
}
