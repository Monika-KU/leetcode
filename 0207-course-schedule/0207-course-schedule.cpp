class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto adjNode : adj[node]) {
                indegree[adjNode]--;

                if (indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        return count == numCourses;
    }
};