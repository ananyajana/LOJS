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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if(!root){
            cout << "Error" << endl;
            return result;
        }
        std::stack<TreeNode*> S;
        do{
            if(root){
                //result.push_back(root->val);
                S.push(root);
                root = root->left;
            }
            if(!root){
                root = S.top();
                S.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }while(!S.empty() || root);
        
    }
};