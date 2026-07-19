class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26);
        
        // Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> inStack(26, false);
        string ans;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Skip if already included
            if (inStack[ch - 'a'])
                continue;

            // Remove larger characters if they appear later
            while (!ans.empty() &&
                   ans.back() > ch &&
                   lastIndex[ans.back() - 'a'] > i) {

                inStack[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            inStack[ch - 'a'] = true;
        }

        return ans;
    }
};