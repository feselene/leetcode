class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0, flip = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }
            if (nums[i] == flip) {
                if (i + k > n) return -1;
                flips++;
                flip ^= 1;
                isFlipped[i] = 1;
            }
        }

        return flips;
    }
};
