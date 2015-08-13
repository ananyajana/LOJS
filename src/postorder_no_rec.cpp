/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if(!root){
            cout << "Error" << endl;
            return result;
        }
        std::stack<TreeNode*> S;
        TreeNode* temp;
        while(!S.empty()){
            if(root){
                if(root->right)
                    S.push(root->right);
                S.push(root);    
                root = root->left;
            }
            if(!root){
                root = S.top();
                S.pop();
				if(!S.empty())
					temp = S.top();
                if(root->right && temp == root->right){
                    S.pop();
                    S.push(root);
                    root = root->right;
                }
                else{
                    result.push_back(root->val);
                    root = NULL;
                }
            }
        }
    }
};