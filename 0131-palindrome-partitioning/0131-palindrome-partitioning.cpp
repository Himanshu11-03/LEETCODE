class Solution {
public:
bool isplain(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s==s2;
}
void gap(string s,vector<vector<string>>&ans,vector<string>&path){
    if(s.size()==0){
        ans.push_back(path);
        return;
    }
    for(int i=0;i<s.size();i++){
        string part=s.substr(0,i+1);
        if(isplain(part)){
        path.push_back(part);
        gap(s.substr(i+1),ans,path);
        path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        gap(s,ans,path);
        return ans;
    }
};