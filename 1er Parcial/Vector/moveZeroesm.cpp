#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	std::vector<int> nums(5); 
	
	nums[0]= 0;
	nums[1]= 1;
	nums[2]= 0;
	nums[3]= 3;
	nums[4]= 12;

	int counter = 0;
	queue<int> q;

	cout << "Original: ";
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}

	// 1 1 0 3 12

	for (int i=0; i<nums.size(); i++) {
		if (nums[i] != 0) {
			q.push(nums[i]);
		}
	}

	int i=0;
	while (!q.empty()) {
		nums[i] = q.front();
		q.pop();
		i++;
	}

	while(i<nums.size()) {
		nums[i] = 0;
		i++;
	}

	cout << "\nNew: ";
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}

	cout << endl << endl;
	return 0;
}