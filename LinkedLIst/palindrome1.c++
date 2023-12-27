// Palindrome check 
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL&&head->next==NULL)
        {
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*curr=slow;
        ListNode*prev=NULL;
        while(curr!=NULL)
        {
            ListNode*nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        ListNode*firsthalf=head;
        ListNode*secondhalf=prev;
        while(secondhalf!=NULL)
        {
            if(firsthalf->val!=secondhalf->val)
            {
                return false;
            }
            firsthalf=firsthalf->next;
            secondhalf=secondhalf->next;
        }
        return true;
    }
};