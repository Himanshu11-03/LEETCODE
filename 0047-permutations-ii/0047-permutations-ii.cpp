
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& nums, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        solve(nums, used);

        return ans;
    }
};
