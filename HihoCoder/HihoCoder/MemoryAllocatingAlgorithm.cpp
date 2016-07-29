#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

struct Block {
	int key;
	int length;
	Block *prev;
	Block *next;
};
Block *head;
Block *p;
Block *endPos;
vector<Block *> pos(200, nullptr);

void init(int m){
	head = new Block();
	head->key = -1;
	head->length = 0;
	head->prev = nullptr;
	head->next = nullptr;

	p = new Block;
	p->key = 0;
	p->length = m;
	p->prev = head;
	p->next = nullptr;
	head->next = p;

	endPos = new Block;
	endPos->key = -1;
	endPos->length = 0;
	endPos->prev = p;
	endPos->next = nullptr;
	p->next = endPos;
}

Block* findEmpty(int len){
	Block* pp = head->next;
	
	while (pp->key != -1) {
		if (pp->key == 0 && pp->length >= len) {
			return pp;
		}
		pp = pp->next;
	}
	
	return nullptr;
}

void insertData(Block* emptyBlock, int key, int len) {
	if (emptyBlock->length == len) {
		emptyBlock->key = key;
	}
	else{
		Block* pp = new Block();
		pp->key = 0;
		pp->length = emptyBlock->length - len;

		pp->prev = emptyBlock;
		pp->next = emptyBlock->next;
		pp->next->prev = pp;

		emptyBlock->key = key;
		emptyBlock->length = len;
		emptyBlock->next = pp;
	}
	pos[key] = emptyBlock;
}

void deleteData(int key) {
	Block *pp = pos[key];

	Block *tp = pp->prev;
	if (tp->key == 0) {
		pp->length = pp->length + tp->length;
		pp->prev = tp->prev;
		pp->prev->next = pp;
		delete tp;
	}
		

	tp = pp->next;
	if (tp->key == 0) {
		pp->length = pp->length + tp->length;
		pp->next = tp->next;
		pp->next->prev = pp;
		delete tp;
	}

	pp->key = 0;
}

int main() {
	map<int, int> rs;
	int lastDeleteData = 0;
	int n, m;
	scanf("%d %d", &n, &m);
	init(m);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);

		while (true) {
			Block *pp = findEmpty(k);
			if (pp != nullptr) {
				insertData(pp, i + 1, k);
				break;
			}
			else {
				lastDeleteData = lastDeleteData + 1;
				deleteData(lastDeleteData);
			}
		}
	}

	Block *pp = head->next;
	int startPos = 0;
	while (pp->key != -1) {
		if (pp->key > 0) {
			rs[pp->key] = startPos;
		}
		startPos += pp->length;
		pp = pp->next;
	}

	for (map<int, int>::iterator it = rs.begin(); it != rs.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}

	system("pause");
	return 0;
}
