#include "utils.hpp"

/* array/vector */
void myPrint(vector<int> &nums) {
  for (auto x : nums) {
    cout << x << " ";
  }
  cout << endl;
}


/* linked list */
void addNode(ListNode *head, int x) {
    ListNode *node = head;
    while (node->next) {
        node = node->next;
    }
    node->next = new ListNode(x);
}

std::string isEmptyNode(ListNode *node) {
    return (node) ? "NotEmpty" : "Empty";
}

void printList(ListNode *head) {
    ListNode *node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
