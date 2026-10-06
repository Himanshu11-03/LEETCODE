class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int bal=0;
        for(char c:s){
            if(c=='('){
                bal++;
            }else{
                if(bal>0){
                    bal--;
                }
                else{
                    open++;
                }

            }
        }
        return open+bal;
    }
};