class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build directed graph: edge a -> b means "a invokes b"
        vector<vector<int>> graph(n);
        for (auto& e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Step 1: BFS from k to find all suspicious methods
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // Step 2: Is there a clean method invoking a suspicious one?
        for (int u = 0; u < n; ++u) {
            if (suspicious[u]) continue;          // only check clean methods
            for (int v : graph[u]) {
                if (suspicious[v]) {              // clean -> suspicious edge found
                    vector<int> all(n);
                    iota(all.begin(), all.end(), 0);
                    return all;                   // unsafe: remove nothing
                }
            }
        }

        // Step 3: Safe to remove — return the clean methods
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (!suspicious[i]) ans.push_back(i);
        return ans;
    }
};