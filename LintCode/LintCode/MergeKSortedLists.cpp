#include <stdlib.h>
#include <stdio.h>
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
    * @param lists: a list of ListNode
    * @return: The head of one sorted list.
    */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if (lists.size() == 1) return lists[0];

        if (lists.size() > 1) {
            return binaryMerge(lists, 0, lists.size() - 1);
        }

        return nullptr;
    }

    ListNode *binaryMerge(vector<ListNode *> &lists, int start, int end) {
        if (end - start == 1) {
            return mergeOperation(lists[start], lists[end]);
        }

        if (end - start > 1) {
            int middle = (end - start) / 2 + start;
            ListNode *left = binaryMerge(lists, start, middle - 1);
            ListNode *right = binaryMerge(lists, middle, end);
            return mergeOperation(left, right);
        }

        return lists[start];
    }

    ListNode *mergeOperation(ListNode *left, ListNode *right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        ListNode *head = new ListNode(INT_MIN);
        ListNode *curr = head;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                curr->next = new ListNode(left->val);
                curr = curr->next;
                left = left->next;
            }
            else {
                curr->next = new ListNode(right->val);
                curr = curr->next;
                right = right->next;
            }
        }

        while (left != nullptr) {
            curr->next = new ListNode(left->val);
            curr = curr->next;
            left = left->next;
        }

        while (right != nullptr) {
            curr->next = new ListNode(right->val);
            curr = curr->next;
            right = right->next;
        }

        return head->next;
    }
};
