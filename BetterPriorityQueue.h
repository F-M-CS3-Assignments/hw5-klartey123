#ifndef BETTER_PRIORITY_QUEUE_H
#define BETTER_PRIORITY_QUEUE_H
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

using namespace std;

#define nodekey_t unsigned long long int
#define INVALID_NODE_KEY ULLONG_MAX

//BPQNode_strut.txt
struct BPQNode {
	int pri = INT_MAX;
	bool visited = false;
	nodekey_t gnode = INVALID_NODE_KEY;
	
	bool operator<(const BPQNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const BPQNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const BPQNode &other) const {
		return this->gnode == other.gnode;
	}
};
class BetterPriorityQueue : public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode> > {
    public:
        // Returns true if the queue contains the specified node
        bool Contains(const BPQNode& n) const;
    
        // Updates the priority of an existing node if the new priority is lower
        bool Update(const BPQNode& n);
    
        // Returns a string of the queue
        string ToString() const;
    
        // Static helper: returns a string of a BPQNode
        static string BPQNodeToString(const BPQNode& n);
    };
    
    #endif // BETTER_PRIORITY_QUEUE_H