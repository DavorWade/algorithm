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
    * @return: The head of linked list.
    */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode *dummy = new ListNode(0);
        // 这个dummy的作用是，把head开头的链表一个个的插入到dummy开头的链表里
        // 所以这里不需要dummy->next = head;

        while (head != NULL) {
            ListNode *temp = dummy;
            ListNode *next = head->next;
            while (temp->next != NULL && temp->next->val <= head->val) {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }

        return dummy->next;
    }
};