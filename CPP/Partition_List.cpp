class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* high = new ListNode(0);
        ListNode* smallHead = small, *highHead = high;
        
        while(head)
        {
            if(head->val<x)
            {
                // put it in small list 
                smallHead->next = head;
                smallHead = smallHead->next;
            }
            else
            {
                // put it in higher list
                highHead->next = head;
                highHead = highHead->next;
            }
            head = head->next;
        }
        
        // joining the two lists
        highHead->next = NULL;
        smallHead->next = high->next;
        
        return small->next;
    }
};
