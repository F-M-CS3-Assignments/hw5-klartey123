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
		
        bool Update(const BPQNode& n);
        bool Contains(const BPQNode& n) const;
        string ToString() const;
        static string BPQNodeToString(const BPQNode& n);
    };
    
    #endif 