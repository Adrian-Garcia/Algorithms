#include <iostream>

using namespace std;


struct TreeNode {
	int val;
 	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void add(TreeNode *r, int val) {

	TreeNode *curr = r;
	TreeNode *father = NULL;

	while (curr != NULL) {

		if (curr->val == val)
			return;

		father = curr;

		curr = (curr->val > val) ?
			curr->left : curr->right;
	}

	if (father->val > val) {
		father->left = new TreeNode(val);
	} else {
		father->right = new TreeNode(val);
	}
}

void preOrder(TreeNode *r) {
	if (r != NULL) {
				
		preOrder(r->left);
		preOrder(r->right);
	}
}

int height(TreeNode *r) {
	
	if (r == NULL)
		return 0;

	int izq = height(r->left);
	int der = height(r->right);

	return 1 + (izq > der ? izq : der);
}

int diameterOfBST(TreeNode *r) {
	if (r != NULL) {
		
		int right, left;
		int dRight, dLeft;
		
		left = height(r->left);
		right = height(r->right);
		
		dLeft = diameterOfBST(r->left); 
		dRight = diameterOfBST(r->right); 
		  
		int max = (dLeft > dRight) ? dLeft : dRight;

		if (max > left+right) {
			return max;
		} 

		else {
			return left+right;
		}
	}
}

int main() {

	TreeNode *test, *aux, *two;

	test = new TreeNode(10);

	add(test, 5);
	add(test, 2);
	add(test, 1);
	add(test, 7);
	add(test, 20);
	add(test, 15);
	add(test, 11);
	add(test, 25);
	add(test, 30);

	// print(test, 2);
	cout << height(test) << endl;
	cout << diameterOfBST(test) << endl;

	return 0;
}