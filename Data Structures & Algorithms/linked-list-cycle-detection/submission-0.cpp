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
    bool hasCycle(ListNode* head) {
        ListNode* speed = head;
        ListNode* slow = head;

        while(speed && speed->next) {
            speed = speed->next->next;
            slow = slow->next;
            if(slow == speed) return true;
        }
        return false;
    }
};
