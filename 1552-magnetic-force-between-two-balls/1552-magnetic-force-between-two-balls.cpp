class Solution {
public:
bool ispossible(vector<int>& a ,int m,int mid){
    int magnet=1;int position=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]-position>=mid){
            magnet++;
            position=a[i];
        if(magnet==m){
            return true;
        }
    }
    }return false;

   

}
    int maxDistance(vector<int>& a, int m) {
        std::sort(a.begin(),a.end());

        int s=1;int end=a.back()-a[0];
        int ans=-1;
        while(s<=end){
         int mid= s+(end-s)/2;
         if(ispossible(a,m,mid)){
            ans=mid;
          s=mid+1;
         }else{
            end=mid-1;
         }
        }
        return ans;
    }
};