class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> numToCount;
        for (int i = 0; i < sortedNums.size(); i++) {
            if (numToCount.find(sortedNums[i]) == numToCount.end()) {
                numToCount[sortedNums[i]] = i;
            }
        }

        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[i] = numToCount[nums[i]];
        }

        return result;
    }
};