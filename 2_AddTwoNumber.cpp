/*
Linked list 基本操作
T(n) = O(|M| + |N|), S(n) = O(|M| + |N|)
M,N是兩個串列的長度
每個位數加起來後判斷要不要進位
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* current = ans, *tmp;
        int carry = 0,sum;
        while(l1 || l2 || carry){
            if(l1 && l2){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else if(l2){
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else{
                sum = carry;
            }
            if(sum >= 10) carry = 1;
            else carry = 0;
            sum %= 10;

            if(ans){
                tmp = new ListNode(sum);
                current->next = tmp;
                current = tmp;
            }
            else{
                ans = new ListNode(sum);
                current = ans;
            }
        }
        return ans;
    }
};