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
        do{
            if(root){
                S.push(root);
                if(root->right)
                    S.push(root->right);
                root = root->left;
            }
            if(!root){
                root = S.top();
                S.pop();
                if(S.empty()){
                    result.push_back(root->val);
                    break;
                }
                temp = S.top();
                if(!root->right ||(temp && temp != root->right)){
                    result.push_back(root->val);
                    root = NULL;
                }
                else{
                    S.push(root);
                    root = root->right;
                }
                
                    
            }
        }while(!S.empty() || root);
    }
};