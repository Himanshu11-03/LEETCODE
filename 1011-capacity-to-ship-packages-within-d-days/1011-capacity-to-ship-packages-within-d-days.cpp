class Solution {
public:
    bool ispossible(vector<int>& a, int days, int mid) {
        int currentweight = 0;
        int daysneeded= 1;
        for (int i = 0; i < a.size(); i++) {
            if (currentweight + a[i] <= mid) {
                 currentweight += a[i];
            } else {
                daysneeded++;
                currentweight = a[i];
            }
        }
        return daysneeded <= days;
    }
    int shipWithinDays(vector<int>& a, int days) {
        
        int start = *max_element(a.begin(), a.end());
        int end = accumulate(a.begin(), a.end(), 0);
        int ans = -1;
        while (start <= end) {
           int  mid = start + (end - start) / 2;
            if (ispossible(a,days,mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            
        }
        return ans;
    }
    
};