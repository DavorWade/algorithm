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
    * @param n: An integer.
    * @return: Nth to last node of a singly linked list.
    */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if (head == NULL || n < 1) {
            return NULL;
        }

        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int j = 0; j < n - 1; ++j) {
            if (p2 == NULL) {
                return NULL;
            }
            p2 = p2->next;
        }
        while (p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
