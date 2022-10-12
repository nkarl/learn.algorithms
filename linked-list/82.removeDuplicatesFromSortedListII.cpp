#include "../utils.hpp"

using std::string;

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;

    int duplicate = head->val;
    if (head->next->val == duplicate) {
        // traverse the list and link to the next node
        while (head->next && head->next->val == duplicate) {
            head = head->next;
        }
        // since the head is still the one which was duplicated, call
        // recursively on the next node and update current head
        head = deleteDuplicates(head->next);
    }
    else {
        // keep the current head and call recursion from the next node
        head->next = deleteDuplicates(head->next);
    }
    return head;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    ListNode   *head = new ListNode(0);
    vector<int> list = {1, 1, 1, 2, 3, 3};
    addNodesFromList(head, list);

    printList(head);
    head = deleteDuplicates(head);
    printList(head);

    return 0;
}
