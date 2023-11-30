/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        int cnt=0;
        TreeNode* temp=root;
        while(temp || !st.empty()){
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();
            st.pop();
            cnt+=1;
            if(cnt==k){
                return temp->val;
            }
            temp=temp->right;
        }
        return 0;
    }
};