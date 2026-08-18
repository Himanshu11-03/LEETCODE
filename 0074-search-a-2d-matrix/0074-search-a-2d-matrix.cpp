class Solution {
public:
bool searchrow(vector<vector<int>>& matrix, int target,int row){
    int n=matrix[0].size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid= st+(end-st)/2;
        if(target==matrix[row][mid]){
            return true;
        }else if(target>matrix[row][mid]){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
        return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
         int n=matrix[0].size();
        int bs=0;
        int sr=0;
        int endr=m-1;
        while(sr<=endr){
            int midr=sr+(endr-sr)/2;
            if(target>=matrix[midr][0]&& target<= matrix[midr][n-1]){
                return searchrow(matrix, target, midr);
            }
            else if(target>matrix[midr][n-1]){
                sr=midr+1;
            }else{
                endr=midr-1;
            }
        }

        return false;
    }
};