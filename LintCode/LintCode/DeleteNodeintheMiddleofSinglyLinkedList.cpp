#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
    * @param node: a node in the list should be deleted
    * @return: nothing
    */
    void deleteNode(ListNode *node) {
        // write your code here
        if (node == nullptr || node->next == nullptr) {
            node = nullptr;
            return;
        }

        node->val = node->next->val;
        node->next = node->next->next;
    }
};
