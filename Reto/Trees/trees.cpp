//Trees
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
		cout << r->val << " ";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void inOrder(TreeNode *r) {
	if (r != NULL) {
		inOrder(r->left);
		cout << r->val << " ";
		inOrder(r->right);
	}
}

void postOrder(TreeNode *r) {
	if (r != NULL) {
		postOrder(r->left);
		postOrder(r->right);
		cout << r->val << " ";
	}
}

int altura(TreeNode *r) {
	if (r == NULL) {
		return 0;
	}

	int izq = altura(r->left);
	int der = altura(r->right);

	return 1 + (izq > der ? izq : der);
}

//Height
int height(TreeNode *r) {
	return altura(r);
}

void print(TreeNode *r, int c) {
	switch(c) {
		case 1:
			preOrder(r);
		break;

		case 2:
			inOrder(r);
		break;

		case 3:
			postOrder(r);
		break;
	}
}

int maint () {
	return 0;
}