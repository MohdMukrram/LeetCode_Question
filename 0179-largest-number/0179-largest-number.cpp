class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        // Convert numbers to strings
        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        // Custom comparator
        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        // If largest number is 0
        if (arr[0] == "0") {
            return "0";
        }

        string ans = "";

        for (string x : arr) {
            ans += x;
        }

        return ans;
    }
};