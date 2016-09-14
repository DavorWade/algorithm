#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
    * @param graph: A list of Directed graph node
    * @param s: the starting Directed graph node
    * @param t: the terminal Directed graph node
    * @return: a boolean value
    */
    bool hasRoute(vector<DirectedGraphNode*> graph,
        DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        int flag = -1;
        bool fg = false;
        for (int i = 0;i<graph.size();i++) {
            if (s->label == graph[i]->label) {
                flag++;
            }
            if (t->label == graph[i]->label) {
                flag++;
            }
        }

        if (flag == 1) fg = calRoute(s, t);

        return fg;
    }

    bool calRoute(DirectedGraphNode* s, DirectedGraphNode* t) {
        bool flag = false;
        if (s->label == t->label) {
            flag = true;
        }
        else {
            vector<DirectedGraphNode *> tempNei = s->neighbors;
            for (int j = 0;j<tempNei.size();j++) {
                flag = calRoute(tempNei[j], t);
                if (flag) break;
            }
        }

        return flag;
    }
};
