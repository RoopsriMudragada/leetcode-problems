/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* temp = head -> next;
        // if(temp -> next == NULL){
        //     return {-1, -1};
        // }
        int pos = 2;
        vector<int>criticalpos;
        while(temp->next != NULL){

            if(temp -> val < prev->val && temp->val < temp->next->val){
                criticalpos.push_back(pos);
            }
            if(temp->val > prev->val && temp->val > temp->next->val){
                criticalpos.push_back(pos);
            }
            prev = temp;
            temp = temp->next; 
            pos++;
        }

        if(criticalpos.size() < 2){
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        for(int i = 1; i < criticalpos.size(); i++){
            minDistance = min(minDistance, (criticalpos[i] - criticalpos[i - 1]));
        }
        int maxDistance = criticalpos.back() - criticalpos.front();

        return {minDistance, maxDistance};
    }
};