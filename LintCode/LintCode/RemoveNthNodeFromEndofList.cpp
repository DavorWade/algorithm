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
    * @param n: An integer.
    * @return: The head of linked list.
    */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *tmp = res;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        while (head != NULL) {
            head = head->next;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;

        return res->next;
    }
};
