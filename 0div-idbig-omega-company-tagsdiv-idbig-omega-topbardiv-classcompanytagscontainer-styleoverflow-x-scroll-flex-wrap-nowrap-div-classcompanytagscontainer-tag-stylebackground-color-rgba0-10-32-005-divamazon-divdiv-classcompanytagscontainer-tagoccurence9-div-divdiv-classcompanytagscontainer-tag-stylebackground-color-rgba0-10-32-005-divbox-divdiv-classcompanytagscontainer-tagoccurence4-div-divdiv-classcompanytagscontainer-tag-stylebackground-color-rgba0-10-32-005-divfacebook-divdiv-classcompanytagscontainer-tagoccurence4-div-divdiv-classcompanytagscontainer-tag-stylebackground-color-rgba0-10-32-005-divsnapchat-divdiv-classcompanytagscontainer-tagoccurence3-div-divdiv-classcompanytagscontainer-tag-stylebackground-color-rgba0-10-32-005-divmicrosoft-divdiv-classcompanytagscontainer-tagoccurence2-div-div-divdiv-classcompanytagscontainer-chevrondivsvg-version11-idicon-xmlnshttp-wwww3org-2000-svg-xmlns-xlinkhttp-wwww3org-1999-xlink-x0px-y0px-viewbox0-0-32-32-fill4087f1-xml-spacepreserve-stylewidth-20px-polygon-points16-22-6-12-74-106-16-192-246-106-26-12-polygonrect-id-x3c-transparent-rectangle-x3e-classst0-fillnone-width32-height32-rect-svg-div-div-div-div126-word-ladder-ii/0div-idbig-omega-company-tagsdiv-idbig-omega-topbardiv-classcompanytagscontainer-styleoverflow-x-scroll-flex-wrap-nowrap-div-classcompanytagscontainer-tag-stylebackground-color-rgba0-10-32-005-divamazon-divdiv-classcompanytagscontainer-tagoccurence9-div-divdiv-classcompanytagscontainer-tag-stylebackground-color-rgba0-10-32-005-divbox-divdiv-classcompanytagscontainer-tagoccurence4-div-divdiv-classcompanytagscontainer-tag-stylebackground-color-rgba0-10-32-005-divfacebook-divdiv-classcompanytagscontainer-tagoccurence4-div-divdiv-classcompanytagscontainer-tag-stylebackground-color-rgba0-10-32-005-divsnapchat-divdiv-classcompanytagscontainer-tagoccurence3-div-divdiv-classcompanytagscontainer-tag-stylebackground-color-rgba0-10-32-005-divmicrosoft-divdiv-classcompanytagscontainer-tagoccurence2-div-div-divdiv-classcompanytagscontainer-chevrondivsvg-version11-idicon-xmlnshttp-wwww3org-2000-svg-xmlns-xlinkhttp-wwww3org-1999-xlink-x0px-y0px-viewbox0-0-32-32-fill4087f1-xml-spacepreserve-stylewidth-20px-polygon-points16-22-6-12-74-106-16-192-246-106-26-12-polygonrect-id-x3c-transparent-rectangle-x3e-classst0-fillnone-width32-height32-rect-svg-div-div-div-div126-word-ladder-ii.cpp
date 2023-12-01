class Solution {
public:
unordered_map<string,int>mp;
vector<vector<string>>ans;
string b;
void dfs(string word,vector<string>sq){
    if(word==b){
        reverse(sq.begin(),sq.end());
        ans.push_back(sq);
        reverse(sq.begin(),sq.end());
        return ;
    }
    int n=word.size();
    int step=mp[word];

    for(int i=0;i<n;i++){
        char org=word[i];
        for(char c='a';c<='z';c++){
            word[i]=c;
            if(mp.find(word)!=mp.end() && mp[word]+1==step){
                sq.push_back(word);
                dfs(word,sq);
                sq.pop_back();
            }
        }
        word[i]=org;
    }
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);

        st.erase(beginWord);
        mp[beginWord]=1;
        int n=beginWord.size();
        b=beginWord;

        while(!q.empty()){
            string word=q.front();
            int steps=mp[word];
            q.pop();

            if(word==endWord){
                break;
            }
            for(int i=0;i<n;i++){
                char org=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        st.erase(word);
                        q.push(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=org;
            }
        }
        if(mp.find(endWord)!=mp.end()){
            vector<string>sq;
            sq.push_back(endWord);
            dfs(endWord,sq);
        }
        return ans;
    }
};