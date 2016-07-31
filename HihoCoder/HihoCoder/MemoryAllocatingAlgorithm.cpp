#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;

struct chunk {
    int v, s, e;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    deque<chunk> que;
    int c;
    bool f = true;

    for (int k = 1; k <= n; ++k) {
        if (f) scanf("%d", &c);
        if (que.empty()) {
            que.push_back({ k, 0, c - 1 });
        }
        else {
            bool flag = false;
            int minK = n + 1;
            int idx = -1;

            for (int i = 0; i < que.size(); ++i) {
                if (minK > que[i].v) {
                    minK = que[i].v;
                    idx = i;
                }
                if (i == 0) {
                    if (c - 1 < que[i].s) {
                        que.push_front({ k, 0, c - 1 });
                        flag = true;
                        break;
                    }
                }
                if (i == que.size() - 1) {
                    if (que[i].e + c < m) {
                        que.push_back({ k, que[i].e + 1, que[i].e + c });
                        flag = true;
                        break;
                    }
                }
                else {
                    if (que[i + 1].s - que[i].e - 1 >= c) {
                        que.insert(que.begin() + i + 1, { k, que[i].e + 1, que[i].e + c });
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                que.erase(que.begin() + idx);
                k--;
                f = false;
            }
            else {
                f = true;
            }
        }
    }

    sort(que.begin(), que.end(), [](const chunk &ch1, const chunk &ch2) {
        return ch1.v < ch2.v;
    });

    for (int k = 0; k < que.size(); ++k) {
        printf("%d %d\n", que[k].v, que[k].s);
    }

    system("pause");
    return 0;
}

/*
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
*/