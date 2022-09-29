#include "../utils.hpp"

using std::string;

struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

void addNode(ListNode *head, int x) {
    ListNode *node = head;
    while (node->next != nullptr) node = node->next;
    node->next = new ListNode(x);
}

string isEmptyNode(ListNode *node) {
    return (node != nullptr) ? "NotEmpty" : "Empty";
}

ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) return head;

    ListNode *curr = head;
    while (curr && curr->next) {
        if (curr->next->val == curr->val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

void printList(ListNode *head) {
    ListNode *node = head;
    for (; node->next != nullptr;) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(0);
    ListNode *node = head;
    addNode(head, 1);
    addNode(head, 1);
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 3);

    printList(head);
    head = deleteDuplicates(head);
    printList(head);
    return 0;
}
