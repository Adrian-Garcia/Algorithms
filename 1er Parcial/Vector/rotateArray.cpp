#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	std::vector<int> nums;
	int k=-8;

	// 0 1 2 3 4 5 6
	//[1,2,3,4,5,6,7]
	//[2 3 4 5 6 7 1] -1
	//[7,1,2,3,4,5,6]  1
	//[5,6,7,1,2,3,4] 3

	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);

	queue<int> q;
	queue<int> r;

	if (k > nums.size()) {
		cout << "1" << endl;
		k = k%nums.size();
	} else if (k < 0 && k > -1*nums.size()) {
		cout << "2" << endl;
		k*=-1;
		k = k%nums.size();
	}

	if (k > 0) {
		for (int i=nums.size()-k; i<nums.size(); i++) {
			q.push(nums[i]);
		}

		for (int i=0; i < nums.size()-k; ++i){
			r.push(nums[i]);
		}	

		int i=0;
		while(!q.empty()) {
			nums[i] = q.front();
			q.pop();
			i++;
		}

		while(!r.empty()) {
			nums[i] = r.front();
			r.pop();
			i++;
		}	
	} 

	else {
		int count = 0;
		for (int i=k; i<nums.size(); i++) {
			q.push(nums[i]);
			count++;
		}

		for (int i=0; i<nums.size()-count; ++i){
			r.push(nums[i]);
		}	

		int i=0;
		while(!q.empty()) {
			nums[i] = q.front();
			q.pop();
			i++;
		}

		while(!r.empty()) {
			nums[i] = r.front();
			r.pop();
			i++;
		}
	}

	for (int i = 0; i < nums.size(); ++i){
		cout << nums[i] << " " ;
	}

	return 0;
}