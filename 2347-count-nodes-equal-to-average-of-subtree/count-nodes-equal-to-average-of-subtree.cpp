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
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int cnt = 0;
        int sum = findSum(root, cnt);
        int result = 0;
        if(root -> val == (sum / cnt)){
            result++;
        }
        result += averageOfSubtree(root->left);
        result += averageOfSubtree(root->right);
        return result;
    }

    int findSum(TreeNode* root, int & cnt){
        if(root == NULL){
            return 0;
        }
        cnt++;

        int lsum = findSum(root -> left, cnt);
        int rsum = findSum(root-> right, cnt);

        return lsum + rsum + root -> val;
    }
};