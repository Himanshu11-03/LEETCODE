class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int lp=0;
        int rp= height.size()-1;
        while(lp<rp){
            int wid=rp-lp;
            int he=min(height[lp],height[rp]);
            int currentwater=wid*he;
            maxwater=max(maxwater,currentwater);
            height[lp]<height[rp] ? lp++:rp--;
        }
        return maxwater;
        
    }
};