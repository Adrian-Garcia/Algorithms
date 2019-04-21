/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

Definition for singly-linked list.
	struct ListNode {
 		int val;
    	ListNode *next;
  	    ListNode(int x) : val(x), next(NULL) {}
  	};
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {

	int m = 2;
	int n = 4;

	ListNode *curr;
	ListNode *temp;

	stack<ListNode> stk;

	//Get to min
	for (int i=1; i<m-1; i++) {
		curr = curr->next;
	}

	//Put everything in the stack
	for (int i=m-1; i<n-1; i++) {
		stk.push(curr->val);
		temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}

	temp = curr->next;

	//Pop stack and push linked list
	for (int i=m-1; i<=n-1; i++) {
		curr->next = new Node(stk.top(), temp);
		curr = curr->next;
		stk.pop();
	}

	return 0;
}

/*
	ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* temp = head;
        ListNode* res = head;
        vector<int> v;
        int i = 1;
        while (head){
            if (i >= m && i <= n)   v.push_back(head->val);
            head = head -> next;
            ++i;
        }
        i = 1;
        int j = 1;
        while (temp){
            if (i >= m && i<=n) {
                temp -> val = v[v.size()-j];
                ++j;
            }
            temp = temp -> next;
            ++i;
        }
        return res;
    }
*/