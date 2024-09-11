class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int xorResult = start ^ goal;
        int count = 0;
        
        while (xorResult > 0) {
            count += xorResult & 1;
            xorResult >>= 1;
        }
        
        return count;
    }
};
