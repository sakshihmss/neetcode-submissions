class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> mapping;
        unordered_map<char, int> indegree;
        int n = words.size();
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                indegree[words[i][j]] = 0;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            int p = word1.length();
            int q = word2.length();
            int j = 0, k = 0;
            bool flag = false;
            while(j < p && k < q)
            {
                if(word1[j] != word2[k])
                {
                    if(mapping[word1[j]].insert(word2[k]).second)
                        indegree[word2[k]]++;
                    flag = true;
                    break;
                }
                j++;
                k++;
            }
            if(!flag)
            {
                if(p > q)
                    return "";
            }
        }
        queue<char> q;
        for(auto i:indegree)
        {
            if(indegree[i.first] == 0)
                q.push(i.first);
        }
        string ans = "";
        while(!q.empty())
        {
            char ch = q.front();
            ans += ch;
            q.pop();
            for(char c:mapping[ch])
            {
                indegree[c]--;
                if(indegree[c] == 0)
                    q.push(c);
            }
        }
        return ans.length() == indegree.size() ? ans : "";
    }
};
