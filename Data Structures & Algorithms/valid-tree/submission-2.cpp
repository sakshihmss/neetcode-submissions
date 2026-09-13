class DSU {
    vector<int> parent;
    vector<int> _rank;
    public:
        DSU(int n)
        {
            parent.resize(n);
            _rank.assign(n, 0);
            for(int i=0;i<n;i++)
                parent[i] = i;
        }

        int find(int x)
        {
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int x, int y)
        {
            int a = find(x);
            int b = find(y);
            if(a == b) return false;
            if(_rank[a] < _rank[b]) swap(a, b);
            parent[b] = a;
            if(_rank[a] == _rank[b])
                _rank[a] += 1;
            return true;
        }
    
};
    
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        if(e != n-1)
            return false;
        DSU dsu(n);
        for(int i=0;i<e;i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            if(!dsu.unite(x, y))
                return false;
        }
        return true;
    }
};
