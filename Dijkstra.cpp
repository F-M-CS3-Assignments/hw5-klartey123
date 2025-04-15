#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Graph.h"
#include "BetterPriorityQueue.h"

using namespace std;

// Dijkstra’s Algorithm using binary heap and adjacency list
// Time Complexity: O(log V)
int dijkstra(nodekey_t start, nodekey_t end, const Graph *g) {
    unordered_map<nodekey_t, int> dist;
    BetterPriorityQueue q;

    // Initialize distances to all nodes as infinity
    for (nodekey_t n : g->GetNodes()) {
        dist[n] = INT_MAX;
    }
    dist[start] = 0;

     // Start exploring from the start node
    BPQNode startNode;
    startNode.gnode = start;
    startNode.pri = 0;
    q.push(startNode);

    while (!q.empty()) {
        BPQNode curr = q.top();
        q.pop();

        // if we already found a better path to this node, skip it
        if (curr.pri > dist[curr.gnode]) {
            continue;
        }

        if (curr.gnode == end) {
            return dist[end];
        }

        // Go through all the neighbors.
        for (const GraphEdge* edge : g->GetOutwardEdgesFrom(curr.gnode)) {
            nodekey_t neighbor = edge->to;
            int newDist = dist[curr.gnode] + edge->weight;

            // if it’s already in the queue, update it. Otherwise push it in.

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;

                BPQNode updated;
                updated.gnode = neighbor;
                updated.pri = newDist;

                if (q.Contains(updated)) {
                    q.Update(updated);
                } else {
                    q.push(updated);
                }
            }
        }
    }

    
    return -1;
}
