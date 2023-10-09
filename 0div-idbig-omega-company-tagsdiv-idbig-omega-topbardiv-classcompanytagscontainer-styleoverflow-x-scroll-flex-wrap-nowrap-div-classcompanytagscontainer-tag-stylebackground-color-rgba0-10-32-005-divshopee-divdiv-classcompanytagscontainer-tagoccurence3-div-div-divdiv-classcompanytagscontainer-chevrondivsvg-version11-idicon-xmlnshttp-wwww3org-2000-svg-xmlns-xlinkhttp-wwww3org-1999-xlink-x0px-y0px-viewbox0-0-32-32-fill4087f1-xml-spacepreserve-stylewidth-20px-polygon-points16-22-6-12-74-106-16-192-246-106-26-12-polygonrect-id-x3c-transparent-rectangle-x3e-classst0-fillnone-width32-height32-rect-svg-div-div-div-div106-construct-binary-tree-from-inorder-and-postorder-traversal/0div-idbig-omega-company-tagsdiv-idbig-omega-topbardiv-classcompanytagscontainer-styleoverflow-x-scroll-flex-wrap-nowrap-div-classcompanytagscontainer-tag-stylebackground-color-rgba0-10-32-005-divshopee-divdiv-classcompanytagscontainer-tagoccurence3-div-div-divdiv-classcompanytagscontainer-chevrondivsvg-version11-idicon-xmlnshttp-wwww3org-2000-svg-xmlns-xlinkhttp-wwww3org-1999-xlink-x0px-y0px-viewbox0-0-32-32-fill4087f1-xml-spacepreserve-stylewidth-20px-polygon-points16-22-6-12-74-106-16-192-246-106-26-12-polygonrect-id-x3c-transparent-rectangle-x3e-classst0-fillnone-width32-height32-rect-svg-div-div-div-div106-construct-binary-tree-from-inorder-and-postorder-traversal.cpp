// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())return NULL;
        map<int, int>m;
        for(int i=0;i<inorder.size();++i){
            m[inorder[i]] = i;
        }
        TreeNode* root= build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
        return root;
    }
    TreeNode* build(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,map<int, int>& m){
        if(ps>pe || is>ie)return  NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = m[postorder[pe]];
        int x = inroot - is;
        root->left = build(inorder,is,inroot-1,postorder,ps,ps+x-1,m);
        root->right = build(inorder,inroot+1,ie,postorder,ps+x,pe-1,m);
        return root;
        
    }
};