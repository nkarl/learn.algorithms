#include "utils.hpp"

/* array/vector */
void myPrint(vector<int> &nums) {
    for (auto x : nums) {
        printf("%d ", x);
    }
    printf("\n");
}

/* linked list */
void addNode(ListNode *head, int x) {
    ListNode *node= head;
    while (node->next) {
        node= node->next;
    }
    node->next= new ListNode(x);
}

void addNodesFromList(ListNode *head, vector<int> list) {
    ListNode *node= head;
    while (node->next) {
        node= node->next;
    }
    for (auto x : list) {
        node= node->next= new ListNode(x);
    }
}

string isEmptyNode(ListNode *node) {
    return (node) ? "NotEmpty" : "Empty";
}

void printList(ListNode *head) {
    ListNode *node= head;
    while (node) {
        printf("%d ", node->val);
        node= node->next;
    }
    printf("\n");
}
