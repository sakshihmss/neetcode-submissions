class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        int sz = prerequisites.size();
        for(int i=0;i<sz;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[front].size();i++)
            {
                indegree[adj[front][i]]--;
                if(indegree[adj[front][i]] == 0)
                    q.push(adj[front][i]);
            }
        }
        return count == numCourses;
    }
};
