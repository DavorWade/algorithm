#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	/**
	* @param head: The head of linked list with a random pointer.
	* @return: A new head of a deep copy of the list.
	*/
	RandomListNode *copyRandomList(RandomListNode *head) {
		// write your code here
		RandomListNode *head_curr = head;

		RandomListNode *header = new RandomListNode();
		RandomListNode *header_curr = header;

		while (head_curr != nullptr) {
			header_curr->next = new RandomListNode(head_curr->label);

			header_curr = header_curr->next;
			head_curr = head_curr->next;
		}

		head_curr = head;
		header_curr = header->next;
		while (head_curr != nullptr) {
			if (head_curr->random == nullptr) {
				header_curr->random = nullptr;
			}
			else {
				RandomListNode *tmp = head;
				int i = 0;

				// int label_random = head_curr->random->label;

				while (tmp != nullptr) {
					if (tmp == head_curr->random) {
						break;
					}
					else {
						tmp = tmp->next;
						i++;
					}
				}

				RandomListNode *temp = header->next;
				int j = 0;
				while (j < i) {
					temp = temp->next;
					j++;
				}
				header_curr->random = temp;
			}

			header_curr = header_curr->next;
			head_curr = head_curr->next;
		}

		return header->next;
	}
};
