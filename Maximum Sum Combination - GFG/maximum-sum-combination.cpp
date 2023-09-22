//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,pair<int,int>> pii;
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pii> pq;
        pq.push({A[n-1]+B[n-1],{n-1,n-1}});
        set<pair<int,int>> s;
        s.insert({n-1,n-1});
        vector<int> ans;
    
        while(k>0){
            auto top=pq.top();
            pq.pop();
            int sum=top.first;
            int x=top.second.first;
            int y=top.second.second;
            
            ans.push_back(sum);
            
            if(s.find({x-1,y})==s.end()){
                pq.push({A[x-1]+B[y],{x-1,y}});
                s.insert({x-1,y});
            }
            
            if(s.find({x,y-1})==s.end()){
                pq.push({A[x]+B[y-1],{x,y-1}});
                s.insert({x,y-1});
            }
            k-=1;
        }
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends