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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        ListNode *nextResultNode = nullptr;
        ListNode *nextNode = nullptr;
        
        while (true) {
            if (l1 == nullptr && l2 == nullptr) {
                break;
            }
            else if (l1 != nullptr && l2 != nullptr) {
                if (l1->val <= l2->val) {
                    nextNode = l1;
                    l1 = l1->next;
                }
                else {
                    nextNode = l2;
                    l2 = l2->next;
                }
            }
            else if (l1 == nullptr && l2 != nullptr) {
                nextNode = l2;
                l2 = l2->next;
            }
            else {
                nextNode = l1;
                l1 = l1->next;
            }
            
            if (nextNode != nullptr) {
                if (result == nullptr) {
                    result = nextNode;
                    nextResultNode = result;
                }
                else {
                    nextResultNode->next = nextNode;
                    nextResultNode = nextResultNode->next;
                }
            }
            else {
                break;
            }
        }
                
        return result;
    }
};
