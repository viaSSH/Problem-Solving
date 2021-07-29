/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> clone;
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
            return node;
        
        
        
        if(clone.find(node) == clone.end()) {
            clone[node] = new Node(node->val);
            for(Node* neighbor : node->neighbors) {
                clone[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return clone[node];
        
        
    }
};