class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if (n < 3)
            return 0;

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return count;
    }
};