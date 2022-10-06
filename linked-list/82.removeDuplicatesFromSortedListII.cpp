#include "../utils.hpp"

using std::string;

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
        return head;
    }

    int sentinel = head->val;
    // If head is found duplicated
    if (head->next->val == sentinel) {
        while (head->next && head->next->val == sentinel) {
            head = head->next;
        }
        // Since head node is still the one which was duplicated calling recursion on next Node and updating current head
        head = deleteDuplicates(head->next);
    }

    // If head isn't duplicated
    else {
        // Leaving current head preserved and calling recursion from the next Node of list
        head->next = deleteDuplicates(head->next);
    }
    return head;

    //if (!head) return head;

    //ListNode *parent = head, *child = parent->next;
    //while (child) {
        //child = (parent->val == child->val)
                    //? parent->next = child->next
                    //: parent       = parent->next;
    //}
    //return head;
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
