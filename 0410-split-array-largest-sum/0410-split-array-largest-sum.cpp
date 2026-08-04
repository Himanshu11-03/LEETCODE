class Solution {
public:
bool isValid(vector<int>& nums, int k,int mid){
    int person=1;
    int pages=0;
    for(int i=0;i<nums.size();i++){
    if(nums[i]>mid){
        return false;
    }
    if(pages+nums[i]<=mid){
        pages+=nums[i];
    }else{
        person++;
        pages=nums[i];
    }
}return person<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(start<=end){
             int mid=start+(end-start)/2;
            if(isValid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
        
    }
};