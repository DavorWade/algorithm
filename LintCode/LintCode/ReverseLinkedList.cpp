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
    * @param head: The first node of linked list.
    * @return: The new head of reversed linked list.
    */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head->next;
        ListNode* new_head = head;
        new_head->next = nullptr;

        while (curr->next != nullptr) {
            ListNode* curr_next = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = curr_next;
        }
        curr->next = new_head;
        new_head = curr;

        return new_head;
    }
};
