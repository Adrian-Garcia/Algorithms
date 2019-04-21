//Find Bottom Left Tree Value
//Given a binary tree, find the leftmost value in the last row of the tree.
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

int levels(TreeNode *r) {

	if (r != NULL)
		return -1;

	queue<TreeNode*> q;
	q.push(r);

	int Nodes[2] = {1,0};

	int prev;
	int small = r->val;

	while (!q.empty()) {
		
		if (q.front()->left != NULL) {
			q.push(q.front()->left);
			Nodes[1]++;
		}

		if (q.front()->right != NULL) {
			q.push(q.front()->right);
			Nodes[1]++;
		}

		q.pop();
		Nodes[0]--;

        if (Nodes[0] == 0 && Nodes[1] > 0) {
        	small = q.front()->val;
        	Nodes[0] = Nodes[1];
        	Nodes[1] = 0;
        }
	}

	return small;
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

		case 4:
			levels(r);
		break;
	}
}

int maint () {

	TreeNode *test;

	test = new TreeNode(2);

	add(test, -1);
	add(test, 3);
	add(test, 1);
	add(test, 5);

	cout << levels(test);

	return 0;
}