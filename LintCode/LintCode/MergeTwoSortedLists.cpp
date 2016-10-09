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
    * @param ListNode l1 is the head of the linked list
    * @param ListNode l2 is the head of the linked list
    * @return: ListNode head of linked list
    */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *head;
        if (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                head = new ListNode(l2->val);
                l2 = l2->next;
            }
            else {
                head = new ListNode(l1->val);
                l1 = l1->next;
            }
        }
        else if (l1 != nullptr) {
            head = new ListNode(l1->val);
            l1 = l1->next;
        }
        else {
            head = new ListNode(l2->val);
            l2 = l2->next;
        }
        ListNode *curr = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l2 = l2->next;
            }
            else {
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                l1 = l1->next;
            }
        }
        while (l1 != nullptr) {
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }

        return head;
    }
};
