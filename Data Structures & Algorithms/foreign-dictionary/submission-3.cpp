class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                indegree[words[i][j]] = 0;
            }
        }
        for(int i=1;i<n;i++)
        {
            string s1 = words[i-1];
            string s2 = words[i];
            int m = s1.length();
            int p = s2.length();
            int j=0, k=0;
            while(j < m && k < p)
            {
                if(s1[j] != s2[k])
                {
                    adj[s1[j]].insert(s2[k]);
                    break;
                }
                j++;
                k++;
            }
            if(j < m && k == p)
                return "";
        }
        for(auto i:adj)
        {
            for(auto j:i.second)
            {
                indegree[j]++;
            }
        }
        queue<char> q;
        for(auto i:indegree)
        {
            if (i.second == 0)
                q.push(i.first);
        }
        string ans = "";
        while(!q.empty())
        {
            char curr = q.front();
            q.pop();
            ans += curr;
            for(auto i:adj[curr])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i); 
            }
        }
        if(ans.length() == indegree.size())
            return ans;
        return "";
    }
};
