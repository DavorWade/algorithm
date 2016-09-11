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

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
    * @param head: The first node of linked list.
    * @return: a tree node
    */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (head == nullptr) return nullptr;

        vector<int> v;
        ListNode *curr = head;
        while (curr != nullptr) {
            v.push_back(curr->val);
            curr = curr->next;
        }

        return dfs(v, 0, v.size());
    }

    TreeNode *dfs(vector<int> &v, int s, int end) {
        int mid = s + (end - s) / 2;
        TreeNode *root = new TreeNode(v[mid]);

        if (mid > s) root->left = dfs(v, s, mid);
        if (end - mid > 1) root->right = dfs(v, mid + 1, end);

        return root;
    }
};

//another solution
class Solution {
public:
    /**
    * @param head: The first node of linked list.
    * @return: a tree node
    * @date: 2016-9-11
    */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (head == nullptr) return nullptr;
        ListNode *curr = head;

        int n = 0;
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        return sortedListToBST(head, 0, n - 1);
    }

    TreeNode* sortedListToBST(ListNode *& list, int start, int end) {
        if (start > end) return NULL;

        // same as (start+end)/2, avoids overflow
        int mid = start + (end - start) / 2;

        TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;

        list = list->next;
        parent->right = sortedListToBST(list, mid + 1, end);

        return parent;
    }
};
