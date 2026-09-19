class Solution {
private:
    pair<int, int> partition3Way(vector<int>& nums, int low, int high) {
       
        int pivotIdx = low + rand() % (high - low + 1);
       swap(nums[pivotIdx], nums[low]);
        
        int pivot = nums[low];
        int lt = low;      
        int gt = high;    
        int i = low + 1;   

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[lt], nums[i]);
                lt++;
                i++;
            } else if (nums[i] > pivot) {
              swap(nums[i], nums[gt]);
                gt--;
            } else {
                i++;
            }
        }
        return {lt, gt};
    }

    void quickSort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            auto [lt, gt] = partition3Way(nums, low, high);
            quickSort(nums, low, lt - 1);
            quickSort(nums, gt + 1, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};