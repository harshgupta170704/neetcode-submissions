class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // 3. Merge the two halves alternately
        ListNode* cur1 = head;
        ListNode* cur2 = prev;

        while (cur2 != nullptr) {
            ListNode* next1 = cur1->next;
            ListNode* next2 = cur2->next;

            cur1->next = cur2;
            cur2->next = next1;

            cur1 = next1;
            cur2 = next2;
        }
    }
};