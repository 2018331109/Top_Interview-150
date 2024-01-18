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
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* cur=new ListNode(0);
        ListNode* temp=cur;
        while(left && right)
        {
            if(left->val <= right->val)
            {
                cur->next=left;
                left=left->next;
            }
            else
            {
                cur->next=right;
                right=right->next;
            }
            cur=cur->next;
        }

        if(left)
        {
            cur->next=left;
        }
        else
        {
            cur->next=right;
        }

        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=slow->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=nullptr;

        return merge(sortList(head), sortList(fast));

        
    }
};
