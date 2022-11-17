class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int first  = area(ax1, ay1, ax2, ay2);
        int second = area(bx1, by1, bx2, by2);
        
        int leftOverlap  = max(ax1, bx1);
        int downOverlap  = max(ay1, by1);
        
        int rightOverlap = min(ax2, bx2);
        int upOverlap    = min(ay2, by2);

        int overlap = area(leftOverlap, downOverlap, rightOverlap, upOverlap);

        return first + second - overlap;
    }

private:
    int area(int left, int down, int right, int up) {
        
        if (left > right || down > up) {
            return 0;
        }
        
        return (right - left) * (up - down);
            
    }
};