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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        ListNode *head = NULL;
        ListNode **lptr = &head;
        
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int x, y;
            
            x = ((l1 == NULL) ? 0 : l1->val);
            y = ((l2 == NULL) ? 0 : l2->val);
            int sum = x + y + carry;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else
                carry = 0;
            
            ListNode *n = new ListNode(sum);
            *lptr = n;
            lptr = &n->next;
            
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }
        if (carry > 0) {
            ListNode *n = new ListNode(carry);
            *lptr = n;
            
        }
            
        return head;
    }
};
