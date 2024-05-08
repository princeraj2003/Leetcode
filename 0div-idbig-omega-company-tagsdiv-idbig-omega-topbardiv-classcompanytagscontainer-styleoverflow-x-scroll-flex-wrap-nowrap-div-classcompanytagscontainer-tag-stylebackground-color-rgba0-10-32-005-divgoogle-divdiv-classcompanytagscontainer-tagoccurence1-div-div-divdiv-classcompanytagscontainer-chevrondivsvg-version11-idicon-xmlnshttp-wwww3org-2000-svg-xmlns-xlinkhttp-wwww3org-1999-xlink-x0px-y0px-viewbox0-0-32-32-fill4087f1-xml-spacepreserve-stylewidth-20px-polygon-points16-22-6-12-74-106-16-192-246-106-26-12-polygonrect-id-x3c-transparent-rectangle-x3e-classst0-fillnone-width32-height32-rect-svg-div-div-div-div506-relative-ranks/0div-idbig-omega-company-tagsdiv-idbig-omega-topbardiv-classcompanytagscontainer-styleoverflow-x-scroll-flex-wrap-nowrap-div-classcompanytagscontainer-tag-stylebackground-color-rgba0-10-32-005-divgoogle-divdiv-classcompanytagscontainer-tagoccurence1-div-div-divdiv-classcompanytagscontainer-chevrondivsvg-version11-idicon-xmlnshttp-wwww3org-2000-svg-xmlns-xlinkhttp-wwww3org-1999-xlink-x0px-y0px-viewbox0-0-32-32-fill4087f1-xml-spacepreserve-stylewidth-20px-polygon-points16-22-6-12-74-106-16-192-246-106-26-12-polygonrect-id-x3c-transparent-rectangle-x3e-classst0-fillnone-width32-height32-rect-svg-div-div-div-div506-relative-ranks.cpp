class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       priority_queue<pair<int,int>>pq;
       int n=score.size();
       for(int i=0;i<n;i++){
        pq.push({score[i],i});
       } 
       int cnt=1;
       vector<string>ans(n," ");
       for(int i=0;i<n;i++){
        if(cnt==1){
            ans[pq.top().second]="Gold Medal";
            cnt++;
        }else if(cnt==2){
            ans[pq.top().second]="Silver Medal";
            cnt++;
        }
        else if(cnt==3){
            ans[pq.top().second]="Bronze Medal";
            cnt++;
        }
        else{
            ans[pq.top().second]=to_string(cnt);
            cnt++;
        }
        pq.pop();
       }
       return ans;
    }
};