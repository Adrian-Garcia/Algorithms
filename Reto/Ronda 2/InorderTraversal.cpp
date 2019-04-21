#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void add(int data) {

	TreeNode *curr = 
}

void inOrder(vector<int> &result, TreeNode *r) {
	if (r != NULL) {
		inOrder(r->left);
		result.push_back(r->val);
		inOrder(r->right);
	}
}

int main() {

	int n, num;
	TreeNode *prueba, *left, *right;

	cin n; 

	for (int i=0; i<n; i++) {

	}

	//----------------------------------------------------------------

	std::vector<int> result;






	//return result

	//---------------------------------------------------------------- 


	for (int i=0; i<result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}