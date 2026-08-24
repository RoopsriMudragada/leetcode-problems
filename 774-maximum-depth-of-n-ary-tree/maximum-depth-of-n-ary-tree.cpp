/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*>q;
        q.push(root);
        int cnt = 0;

        if(root == nullptr){
            return 0;
        }

        vector<vector<int>>ans;
        while(!q.empty()){
            int size = q.size();
            vector<int>lvl;

            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();

                lvl.push_back(node->val);

                for(auto &it : node->children ){
                    q.push(it);
                }
            }
            cnt++;
            ans.push_back(lvl);
        }
        return cnt;
    }
};