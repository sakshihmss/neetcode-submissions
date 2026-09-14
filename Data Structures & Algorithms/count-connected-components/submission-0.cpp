class DSU {
    vector<int> parent;
    vector<int> _rank;
    public:
        DSU(int n)
        {
            parent.resize(n);
            _rank.assign(n, 0);
            for(int i=0;i<n;i++)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            if(parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
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
                _rank[a]++;
            return true;
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        int count = n;
        DSU dsu(n);
        for(int i=0;i<e;i++)
        {
            if(dsu.unite(edges[i][0], edges[i][1]))
               count--;
        }
        return count;
    }
};
