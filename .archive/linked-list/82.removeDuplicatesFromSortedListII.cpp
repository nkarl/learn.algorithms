#include "../utils.hpp"

using std::string;

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;

    int duplicate = head->val;
    if (head->next->val == duplicate) {
        // traverse the list and link to the next node until the value no
        // longer repeats.
        while (head->next && head->next->val == duplicate) {
            head = head->next;
        }
        // since the head is the original duplicate (we have to remove all
        // repeating nodes), recur on the next node and update the current
        // head.
        head = deleteDuplicates(head->next);
    }
    else {
        // keep the current head and recur on the next node.
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
