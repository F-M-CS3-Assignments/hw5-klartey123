#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Graph.h"
#include "BetterPriorityQueue.h"

using namespace std;

// Dijkstra’s Algorithm using binary heap and adjacency list
// Time Complexity: O((V + E) * log V)
int dijkstra(nodekey_t start, nodekey_t end, const Graph *g) {
    unordered_map<nodekey_t, int> dist;
    BetterPriorityQueue q;

    // Initialize distances to all nodes as infinity
    for (nodekey_t n : g->GetNodes()) {
        dist[n] = INT_MAX;
    }
    dist[start] = 0;

    // Add start node to the priority queue
    BPQNode startNode;
    startNode.gnode = start;
    startNode.pri = 0;
    q.push(startNode);

    while (!q.empty()) {
        BPQNode curr = q.top();
        q.pop();

        // Skip if we’ve already found a shorter path to this node
        if (curr.pri > dist[curr.gnode]) {
            continue;
        }

        if (curr.gnode == end) {
            return dist[end];
        }

        for (const GraphEdge* edge : g->GetOutwardEdgesFrom(curr.gnode)) {
            nodekey_t neighbor = edge->to;
            int newDist = dist[curr.gnode] + edge->weight;

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

    // If we get here, there's no path to the end node
    return -1;
}
