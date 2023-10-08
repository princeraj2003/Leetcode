class Solution {
public:
    int differenceOfSums(int n, int m) {
        vector<int>notdivisible;
        vector<int>divisible;
        int sum1=0;
        int sum2=0;
        for(int i=1;i<=n;i++){
            if(i%m==0){
                divisible.push_back(i);
                
            }else{
                notdivisible.push_back(i);
            }
        }
        for(int i=0;i<divisible.size();i++){
            sum1+=divisible[i];
        }
        for(int j=0;j<notdivisible.size();j++){
            sum2+=notdivisible[j];
        }
        int ans=sum2-sum1;
        return ans;
    }
};