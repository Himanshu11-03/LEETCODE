
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i <= n - k; i++) {
            int diff = nums[i + k - 1] - nums[i];
            ans = min(ans, diff);
        }
        return ans;
    }
};
