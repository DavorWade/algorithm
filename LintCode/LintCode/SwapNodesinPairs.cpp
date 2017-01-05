#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
    * @param head a ListNode
    * @return a ListNode
    */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* curr = root;

        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tem = curr->next->next;
            curr->next->next = curr->next->next->next;
            tem->next = curr->next;
            curr->next = tem;

            curr = curr->next->next;
        }

        return root->next;
    }
};
