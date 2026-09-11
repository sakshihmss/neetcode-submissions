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
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        Node* root = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz > 0)
            {
                Node* temp = q.front();
                q.pop();
                if(mp.find(temp) == mp.end()) 
                    mp[temp] = new Node(temp->val);
                for(int i=0;i<temp->neighbors.size();i++)
                {
                    Node* n = temp->neighbors[i];
                    if(mp.find(n) == mp.end())
                    {
                        mp[n] = new Node(n->val);
                        q.push(n);
                    }
                    mp[temp]->neighbors.push_back(mp[n]);
                }
                sz--;
            }
        }
        return mp[node];
    }
};
