class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
             int high = *max_element(quantities.begin(), quantities.end());
             int ans=0;
             while(low<=high){
               int mid=low+(high -low)/2;
                int stores = 0;

            for (int quantity : quantities) {
                stores += (quantity + mid - 1) / mid;
            }

                if(stores<=n){
                    ans=mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
             }
             return ans;
    }
};