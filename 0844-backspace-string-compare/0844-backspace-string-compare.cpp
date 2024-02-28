
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//        stack<char>st1;
//        stack<char>st2;
//        for(int i=0;i<s.size();i++){
//            if(s[i]!='#'){
//                st1.push(s[i]);
//            }
//            else if (!st1.empty()){
//                st1.pop();
//            }
//        }
//        for(int i=0;i<t.size();i++){
//            if(t[i]!='#'){
//                st2.push(t[i]);
//            }
//            else if (!st2.empty()){
//                st2.pop();
//            }
//        }
//        vector<char>s1;
//        while(!st1.empty()){
//            s1.push_back(st1.top());
//            st1.pop();
//        }
      
//        vector<char>t1;
//        while(!st2.empty()){
//            t1.push_back(st2.top());
//            st2.pop();
//        }

// if(s1==t1){
//     return true;
// }
//     return false;
//     }
// };
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a , b;
        for (auto v: s){
            if(v!='#' )
                a.push_back(v);
            else if (!a.empty())
                a.pop_back();
        }
        for (auto v: t){
            if(v!='#' )
                b.push_back(v);
            else if (!b.empty())
                b.pop_back();
        }
        return (a==b);
    }
};