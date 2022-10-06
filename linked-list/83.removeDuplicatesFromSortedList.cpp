#include "../utils.hpp"

using std::string;

ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) return head;

    ListNode *parent = head, *child = parent->next;
    while (child) {
        child = (child->val == parent->val)
                    ? parent->next = child->next
                    : parent       = parent->next;
        // if (child->val == parent->val)
        // child = parent->next = child->next;
        // else
        // child = parent = parent->next;
    }
    return head;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(0);
    vector<int> list = {1, 1, 1, 2, 3, 3};
    addNodesFromList(head, list);

    printList(head);
    head = deleteDuplicates(head);
    printList(head);

    return 0;
}
