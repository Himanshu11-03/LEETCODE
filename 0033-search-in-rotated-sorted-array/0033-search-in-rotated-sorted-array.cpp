class Solution {
public:
    int search(vector<int>& a, int target) {
        int start = 0;
        int end = a.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (a[mid] == target) {
                return mid;
            }
            if (a[start] <= a[mid]) {
                if (a[start] <= target && target <= a[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (a[mid] < target && target <= a[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};