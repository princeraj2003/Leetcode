class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int>st;
        for(auto i:students)
        st.push(i);
        stack<int>sand;
        for(int i=n-1;i>=0;i--)
            sand.push(sandwiches[i]);
            int ans=0;
            while(!st.empty() && ans<st.size()){
                if(sand.top()==st.front()){
                    sand.pop();
                    st.pop();
                    ans=0;
                }else{
                    st.push(st.front());
                    st.pop();
                    ans++;
                }
            }
            return st.size();
    }
};