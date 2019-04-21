#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode* deleteUnique(ListNode* head) {

	if (head == NULL)
		return head;

	ListNode *temp;

	while (head->next != NULL && head->val != head->next->val) {
		temp = head;
		head = head->next;
		delete temp;
	}

	ListNode *curr = head;
	bool flag = false;

	while (curr->next != NULL) {

		if (curr->val == curr->next->val) {
			curr = curr->next;
			flag = true;
		}

		else if (flag) {
			curr = curr->next;
			flag = false;
		}

		else {
			temp = curr;
			curr->next = curr->next->next;
			curr->next;
			delete temp;
			flag = false;
		}
	}

	if (head != NULL && head->next == NULL) {
		delete head;
		head = NULL;
	}

	return head;
}

int main() {
	
	ListNode *prueba, *aux, *dos;
	int n, num;
	cin >> n >> num;
	prueba = new ListNode(num);
	aux = prueba;
	for (int i = 0; i < n-1; i++) {
		cin >> num;
		aux->next = new ListNode(num);
		aux = aux->next;
	}
	dos = deleteUnique(prueba);
	aux = dos;
	while (aux != NULL) {
		cout << aux->val << " ";
		aux = aux->next;
	}
	cout << "END\n";

	cout << endl;

	return 0;
}




