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
    int secondMin = INT_MAX;
    bool found = false;
    void solve(TreeNode* root, int mini){
        if(root == NULL){
            return;
        }
        if(root->val > mini){
            secondMin = min(secondMin, root->val);
            found = true;
        }
        solve(root->left, mini);
        solve(root->right, mini);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        int mini = root->val;
        solve(root, mini);

        if(!found){
            return -1;
        }
        
        return secondMin;
    }
};