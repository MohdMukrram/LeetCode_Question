class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1];
        int x2 = rec1[2], y2 = rec1[3];

        int a1 = rec2[0], b1 = rec2[1];
        int a2 = rec2[2], b2 = rec2[3];

        return min(x2, a2) > max(x1, a1) && min(y2, b2) > max(y1, b1);
    }
};