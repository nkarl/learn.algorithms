#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::swap;

template<typename T>
void myPrintHelp(T x);

template<typename T>
void myPrint(vector<T> &vec);

struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(INT32_MAX), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

string isEmptyNode(ListNode *node);
void   addNode(ListNode *head, int x);
void   addNodesFromList(ListNode *head, vector<int> list);
void   printList(ListNode *head);

#endif
