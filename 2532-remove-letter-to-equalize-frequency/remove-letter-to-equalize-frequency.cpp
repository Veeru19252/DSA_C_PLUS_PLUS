class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> count(26, 0);
        
        // Count frequency of each character
        for (char c : word) {
            count[c - 'a']++;
        }
        
        // Try removing one occurrence of each character
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) continue;
            
            // Simulate removal
            count[i]--;
            
            // Find all non-zero frequencies
            int target = -1;
            bool valid = true;
            
            for (int j = 0; j < 26; ++j) {
                if (count[j] == 0) continue;
                
                if (target == -1) {
                    target = count[j];
                } else if (count[j] != target) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) return true;
            
            // Restore
            count[i]++;
        }
        
        return false;
    }
};