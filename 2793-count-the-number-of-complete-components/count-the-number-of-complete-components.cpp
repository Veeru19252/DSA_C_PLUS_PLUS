class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // DFS to find component
                int nodes = 0;
                int totalEdges = 0;
                dfs(i, graph, visited, nodes, totalEdges);
                
                // Check if complete: k*(k-1) == degree_sum
                if (nodes * (nodes - 1) == totalEdges) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited,
             int& nodes, int& totalEdges) {
        visited[node] = true;
        nodes++;
        totalEdges += graph[node].size();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, nodes, totalEdges);
            }
        }
    }
};