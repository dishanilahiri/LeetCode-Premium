Question->
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Code:

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
public:
    map<Node*,Node*> mapping;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        
        if(mapping.find(node)==mapping.end())
        {
            mapping[node]=new Node(node->val);
            for(auto it:node->neighbors)
            {
                mapping[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return mapping[node];
    }
};
