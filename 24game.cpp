class Solution {
public:
    bool judgePoint24(vector<int>& cards, double target = 24) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums, target);
    }

private:
    bool dfs(vector<double>& nums, double target) {
        if (nums.size() == 1) return fabs(nums[0] - target) < 1e-6;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    vector<double> nextNums;
                    for (int k = 0; k < nums.size(); ++k) {
                        if (k != i && k != j) nextNums.push_back(nums[k]);
                    }
                    for (double val : compute(nums[i], nums[j])) {
                        nextNums.push_back(val);
                        if (dfs(nextNums, target)) return true;
                        nextNums.pop_back();
                    }
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        return {a + b, a - b, b - a, a * b, a / b, b / a};
    }
};
