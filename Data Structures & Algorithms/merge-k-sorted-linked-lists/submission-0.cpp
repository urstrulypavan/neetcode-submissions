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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for(int i=0; i<lists.size(); ++i) {
            ListNode* cur = lists[i];
            while(cur) {
                arr.push_back(cur->val);
                cur = cur->next;
            }
        }
        sort(arr.begin(), arr.end());

        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        for(int &val : arr) {
            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = tail->next;
        }
        return head->next;
    }
};
