#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

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
    * @return: Any topological order for the given graph.
    */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> rs;
        if (graph.empty()) return rs;

        vector<int> incomming(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i]->neighbors.size(); j++) {
                incomming[graph[i]->neighbors[j]->label]++;
            }
        }

        int pos = containZero(incomming);
        while (pos != -1) {
            incomming[pos] = -1;
            rs.push_back(graph[pos]);

            for (int j = 0; j < graph[pos]->neighbors.size(); j++) {
                incomming[graph[pos]->neighbors[j]->label]--;
            }

            pos = containZero(incomming);
        }

        return rs;
    }

    int containZero(const vector<int> &incomming) {
        for (int i = 0; i < incomming.size(); i++) {
            if (incomming[i] == 0) return i;
        }

        return -1;
    }
};

