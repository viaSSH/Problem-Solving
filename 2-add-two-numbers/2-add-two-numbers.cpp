// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * l3 = new ListNode();
        ListNode *temp = l3;

        bool up = false;
        
        while(l1 != NULL || l2 !=NULL || up) {
            int a = 0; int b = 0;
            if(l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }
            
            int sum = a + b;
            if(up) sum++;
            // cout << a << ", " << b << endl;
            if(sum > 9) {
                sum = sum % 10;
                up = true;
            }
            else{
                up = false;
            }
            ListNode *node = new ListNode(sum);
            
            temp->next = node;
            temp = temp->next;
            
        }
        
        return l3->next;
    }
};