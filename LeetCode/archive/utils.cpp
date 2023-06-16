#include "utils.hpp"

enum TYPESWITCH
{
    CHAR   = 'c',
    INTEGER= 'i',
    FLOAT  = 'f'
};

template<typename T>
void myPrintHelp(T x) {
    if (*typeid(x).name() == CHAR) {
        printf("%c, ", x);
        return;
    }
    if (*typeid(x).name() == INTEGER) {
        printf("%d, ", x);
        return;
    }
    if (*typeid(x).name() == FLOAT) {
        printf("%f, ", x);
        return;
    }
    else {
        //if (std::strcmp("NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE", typeid(x).name()))
            //printf("%s ", x.c_str());
        cout << x << ", ";
    }
}

/* array/vector */
template<typename T>
void myPrint(vector<T> &vec) {
    printf("input vector: [ ");
    for (auto x : vec) {
        // printf("%d ", x);
        myPrintHelp(x);
    }
    printf("]\n\n");
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
