
#include "BetterPriorityQueue.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// update, it will update the prioity of the node. Only if the new one is lower. 
// then it will rebuild the heap 
bool BetterPriorityQueue::Update(const BPQNode& n) {
    vector<BPQNode> items;
    bool found = false;

    for (BPQNode& curNode : this->c) {
        if (curNode.gnode == n.gnode && n.pri < curNode.pri) {
            curNode.pri = n.pri;
            found = true;
        }
        items.push_back(curNode);
    }

    this->c.clear();

    for (size_t i = 0; i < items.size(); i++) {
        this->push(items.at(i));
    }

    return found;
}
// convert a single node into a string.
string BetterPriorityQueue::BPQNodeToString(const BPQNode& n) {
	return "(" + to_string(n.gnode) + ", pri: " + to_string(n.pri) + ")";
}

//contains;
// it will check if a nodes has already been added 
bool BetterPriorityQueue::Contains(const BPQNode& n) const {
    for (const BPQNode& item : this->c) {
        if (item == n) { 
            return true;
        }
    }
    return false;
}


// the it returns the format in which the queue in the priotiy will be represnted. 
string BetterPriorityQueue::ToString() const{
    string result = "[";
    for (size_t i = 0; i < this->c.size(); i++) {
        result += BPQNodeToString(this->c[i]);
        if (i < this->c.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}


