//Upvote  and Comment
class Solution {
public:
    void reorderList(ListNode* head) {
        //base case i.e if the linked list has zero,one or two elments just return it
        if(!head || !head->next || !head->next->next) return;
        
        //Find the penultimate node i.e second last node of the linkedlist
        ListNode* penultimate = head;
        while (penultimate->next->next) penultimate = penultimate->next;
        
        // Link the penultimate with the second element
        penultimate->next->next = head->next;
        head->next = penultimate->next;
        
        //Again set the penultimate to the the last 
        penultimate->next = NULL;
        
        // Do the above steps rcursive
        reorderList(head->next->next);
    }
};