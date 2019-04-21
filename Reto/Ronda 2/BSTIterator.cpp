#include <iostream>
#include <queue>

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

queue<TreeNode*> q;

void inOrderQueue(TreeNode *r) {
	if (r != NULL) {
		inOrderQueue(r->left);
		q.push(r);
		inOrderQueue(r->right);
	}
}

void BSTIterator(TreeNode *root) {
	inOrderQueue(root);
}

bool hasNext() {
	return q.empty() ?
		true : false;
}

void next() {

	TreeNode *res;

	res = q.front();
	q.pop();

	cout << res->val;
	// return res;
}

int main() {

	TreeNode *test, *aux, *two;

	test = new TreeNode(7);

	add(test, 3);
	add(test, 15);
	add(test, 9);
	add(test, 20);

	inOrder(test);

	return 0;
}