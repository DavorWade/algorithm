#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
    * @param node: A undirected graph node
    * @return: A undirected graph node
    */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node == nullptr) return nullptr;

        unordered_map<int, UndirectedGraphNode *> visited;
        queue<UndirectedGraphNode *> q;
        q.push(node);

        UndirectedGraphNode *rs = new UndirectedGraphNode(node->label);
        visited[node->label] = rs;

        while (!q.empty()) {
            UndirectedGraphNode *curr = q.front();
            q.pop();

            for (int i = 0; i < curr->neighbors.size(); i++) {
                if (visited.find(curr->neighbors[i]->label) == visited.end()) {
                    rs = new UndirectedGraphNode(curr->neighbors[i]->label);

                    visited[curr->neighbors[i]->label] = rs;
                    q.push(curr->neighbors[i]);
                    visited[curr->label]->neighbors.push_back(rs);
                }
                else {
                    visited[curr->label]->neighbors.push_back(visited[curr->neighbors[i]->label]);
                }
            }
        }

        return visited[node->label];
    }
};
