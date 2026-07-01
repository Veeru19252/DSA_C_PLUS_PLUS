class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
         int n = positions.size();
        
        // Create indices array [0, 1, 2, ..., n-1]
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort indices by position (to process robots left to right)
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });
        
        stack<int> stk;  // Stack to store indices of right-moving robots
        
        // Process robots in position order
        for (int i : idx) {
            if (directions[i] == 'R') {
                // Right-moving robot: push to stack
                stk.push(i);
            } else {
                // Left-moving robot: handle collisions with right-moving robots
                while (!stk.empty() && healths[i] > 0) {
                    int j = stk.top();  // Right-moving robot at top of stack
                    
                    if (healths[j] < healths[i]) {
                        // Right robot dies, left robot continues with -1 health
                        stk.pop();
                        healths[j] = 0;
                        healths[i]--;
                    } else if (healths[j] > healths[i]) {
                        // Left robot dies, right robot continues with -1 health
                        healths[j]--;
                        healths[i] = 0;
                    } else {
                        // Both robots have equal health: both die
                        stk.pop();
                        healths[j] = 0;
                        healths[i] = 0;
                    }
                }
            }
        }
        
        // Collect survivors in original order
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};