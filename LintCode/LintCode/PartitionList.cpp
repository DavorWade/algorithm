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
    * @param x: an integer
    * @return: a ListNode
    */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        //链表就弄个新的head，使用next
        if (head == NULL) return NULL;

        ListNode *leftDummy = new ListNode(0);
        ListNode *left = leftDummy;
        ListNode *rightDummy = new ListNode(0);
        ListNode *right = rightDummy;
        ListNode *node = head;
        while (node != NULL) {
            if (node->val < x) {
                left->next = node;
                left = left->next;
            }
            else {
                right->next = node;
                right = right->next;
            }
            node = node->next;
        }
        // post-processing
        right->next = NULL;
        left->next = rightDummy->next;

        return leftDummy->next;
    }
};


