#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void myPrint(vector<int> &nums);

struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

void addNode(ListNode *head, int x); 
std::string isEmptyNode(ListNode *node);
void printList(ListNode *head);

#endif
