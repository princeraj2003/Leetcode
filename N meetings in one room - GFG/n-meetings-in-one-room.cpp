//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        vector<vector<int> > v;
        
        for(int i = 0; i < n; i++){
            
            v.push_back({end[i],start[i]});
        }
        
        int count = 0;
        
        sort(v.begin(),v.end());
        
        int it = -1;
        
        for(int i = 0; i < n; i++){
            
            if(v[i][1] > it){
                count++;
                it = v[i][0];
            }

        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends