class Solution {
public:
    int solve(int mid,vector<int>& bloomDay, int m, int k){
        int buqCnt=0;
        int consecutive=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consecutive++;
            }else{
                consecutive=0;
            }
            if(consecutive==k){
                buqCnt++;
                consecutive=0;
            }
        }
        return buqCnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int start =1;
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int minDay=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(solve(mid,bloomDay,m,k)>=m){
                minDay=mid;
                end=mid-1;
            }else{
                
                start=mid+1;
            }
        }
        return minDay;
    }
};