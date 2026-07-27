class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        bool allUpper = true;

        bool allLower = true;

        for(char c : word) {
            if(islower(c)) allUpper = false;
            if(isupper(c)) allLower = false;
        }

        // Case 3: First uppercase, rest lowercase
        bool firstUpperRestLower = isupper(word[0]);
        for(int i = 1; i < n; i++) {
            if(!islower(word[i])) {
                firstUpperRestLower = false;
                break;
            }
        }

        return allUpper || allLower || firstUpperRestLower;
    }
};