#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	//Input: [2,0,2,1,1,0]
	//Output: [0,0,1,1,2,2]

	std::vector<int> nums;

	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);

	for (int j=0; j<nums.size(); j++) {
		cout << nums[j] << " ";
	}

	//----------------------------------------------

	queue<int> cero;
	queue<int> one;
	queue<int> two;

	int i;

	for (i=0; i<nums.size(); i++){
		if (nums[i] == 0)
			cero.push(nums[i]);

		if (nums[i] == 1)
			one.push(nums[i]);

		if (nums[i] == 2)
			two.push(nums[i]);
	}

	i=0;
	while (!cero.empty()) {
		nums[i] = cero.front();
		cero.pop();
		i++;
	}

	while (!one.empty()) {
		nums[i] = one.front();
		one.pop();
		i++;
	}

	while (!two.empty()) {
		nums[i] = two.front();
		two.pop();
		i++;
	}

	//--------------------------------------------
	cout << endl;
	for (int j=0; j<nums.size(); j++) {
		cout << nums[j] << " ";
	}

	return 0;
}