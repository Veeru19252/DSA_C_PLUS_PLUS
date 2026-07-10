class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, 
                                      vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> sortedNums;
        vector<int> indexMap(n);
        vector<pair<int, int>> sortedNumAndIndexes;

        // Step 1: Sort nodes by value with original indices
        for (int i = 0; i < n; ++i)
            sortedNumAndIndexes.emplace_back(nums[i], i);
        
        ranges::sort(sortedNumAndIndexes);

        // Build sorted values and reverse mapping
        for (int i = 0; i < n; ++i) {
            const auto& [num, sortedIndex] = sortedNumAndIndexes[i];
            sortedNums.push_back(num);
            indexMap[sortedIndex] = i;
        }

        // Step 2: Binary lifting - optimal LOG calculation
        const int maxLevel = std::bit_width(static_cast<unsigned>(n)) + 1;
        
        // jump[i][j] := farthest index reachable from i using 2^j jumps
        vector<vector<int>> jump(n, vector<int>(maxLevel));

        // Step 3: Two-pointer to find farthest reachable for each position
        int right = 0;
        for (int i = 0; i < n; ++i) {
            while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff)
                ++right;
            jump[i][0] = right;
        }

        // Step 4: Build binary lifting table
        for (int level = 1; level < maxLevel; ++level)
            for (int i = 0; i < n; ++i) {
                const int prevJump = jump[i][level - 1];
                jump[i][level] = jump[prevJump][level - 1];
            }

        // Step 5: Answer queries using recursive binary lifting
        for (const vector<int>& query : queries) {
            const int u = query[0];
            const int v = query[1];
            const int uIndex = indexMap[u];
            const int vIndex = indexMap[v];
            const int start = min(uIndex, vIndex);
            const int end = max(uIndex, vIndex);
            const int res = minJumps(jump, start, end, maxLevel - 1);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }

private:
    // Recursive binary lifting for minimum jumps
    int minJumps(const vector<vector<int>>& jump, int start, int end, int level) {
        // Base cases
        if (start == end) return 0;
        if (jump[start][0] >= end) return 1;
        if (jump[start][level] < end) return INT_MAX;

        // Find the largest jump that doesn't overshoot
        int j = level;
        for (; j >= 0; --j)
            if (jump[start][j] < end)
                break;

        // Jump and recurse with remaining distance
        return (1 << j) + minJumps(jump, jump[start][j], end, j);
    }
};