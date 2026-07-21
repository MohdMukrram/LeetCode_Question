class Solution {
public:

    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;

        while (n != 1) {

            // Cycle detected
            if (st.count(n)) {
                return false;
            }

            st.insert(n);

            n = getNext(n);
        }

        return true;
    }
};