class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        char y='a';
        for(char x:key){
            if(x!=' ' && mp.find(x)==mp.end())
            mp.insert({x,y++});
        }
        string ans="";
        for(char x:message){
            if(x!=' ')
            ans+=mp[x];
            else{
                ans+=' ';
            }
        }
        return ans;
    }
};