/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* , int > HashNode ;
        ListNode* temp = head;
        if ( head==NULL || head->next==NULL) return false;
        while(temp!= NULL)
        {
            if(HashNode.find(temp)!= HashNode.end()) return true;
            HashNode[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};