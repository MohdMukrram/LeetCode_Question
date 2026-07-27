class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for(char c : s) {
            freq[c - 'a']++;
        }

        vector<bool> used(26, false);
        string st;

        for(char c : s) {
            freq[c - 'a']--;

            // Already included
            if(used[c - 'a']) {
                continue;
            }

            // Remove larger characters if they appear later
            while(!st.empty() && 
                  st.back() > c && 
                  freq[st.back() - 'a'] > 0) {
                
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};