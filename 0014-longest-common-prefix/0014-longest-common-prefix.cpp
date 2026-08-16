class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
           if (strs.empty()) return "";
           string first=strs[0];
          for (int i=0;i<first.length();i++){
            char curr_char=first[i];
            for (int j=0;j<strs.size();j++){
                if (i >= strs[j].length() || strs[j][i] !=curr_char){
                    return first.substr(0,i);
                }
            }
          }
        return first;
    }
};