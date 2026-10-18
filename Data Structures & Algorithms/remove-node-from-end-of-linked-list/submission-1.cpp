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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) return nullptr;
        ListNode* cur=head;
        int length=1;
        while(cur->next!=nullptr)
        {
            length++;
            cur=cur->next;
        }
        int m =length-n;
        ListNode* prev;
        cur=head;
        ListNode* next;
        next=cur->next;
        
       if(m == 0) return head->next;
        while(m--)
        {
            prev=cur;
          cur=cur->next;
          next=next->next;

        }
        cur->next=nullptr;
        prev->next=next;
        return head;

    }
};
