#include <vector>

using namespace std;

class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, int index,
                        vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (index == candidates.size() || target < 0) {
            return;
        }

        current.push_back(candidates[index]);
        combinationSum(candidates, target - candidates[index], index, current,
                       result);
        current.pop_back();

        combinationSum(candidates, target, index + 1, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        combinationSum(candidates, target, 0, current, result);
        return result;
    }
};