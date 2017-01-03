#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

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
    * @param head: The first node of linked list.
    * @return: head node
    */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == nullptr) return nullptr;

        ListNode *curr = head;
        while (curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};
