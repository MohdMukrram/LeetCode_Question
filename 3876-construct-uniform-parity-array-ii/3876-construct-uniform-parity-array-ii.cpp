

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> ravolqedin = nums1; // required variable
        
        sort(ravolqedin.begin(), ravolqedin.end());

        int minVal = ravolqedin[0];
        int targetParity = minVal % 2;

        for (int i = 1; i < ravolqedin.size(); i++) {
            // if parity different AND cannot subtract smaller to fix
            if ((ravolqedin[i] % 2) != targetParity) {
                // try subtract minVal
                if ((ravolqedin[i] - minVal) % 2 != targetParity) {
                    return false;
                }
            }
        }

        return true;
    }
};