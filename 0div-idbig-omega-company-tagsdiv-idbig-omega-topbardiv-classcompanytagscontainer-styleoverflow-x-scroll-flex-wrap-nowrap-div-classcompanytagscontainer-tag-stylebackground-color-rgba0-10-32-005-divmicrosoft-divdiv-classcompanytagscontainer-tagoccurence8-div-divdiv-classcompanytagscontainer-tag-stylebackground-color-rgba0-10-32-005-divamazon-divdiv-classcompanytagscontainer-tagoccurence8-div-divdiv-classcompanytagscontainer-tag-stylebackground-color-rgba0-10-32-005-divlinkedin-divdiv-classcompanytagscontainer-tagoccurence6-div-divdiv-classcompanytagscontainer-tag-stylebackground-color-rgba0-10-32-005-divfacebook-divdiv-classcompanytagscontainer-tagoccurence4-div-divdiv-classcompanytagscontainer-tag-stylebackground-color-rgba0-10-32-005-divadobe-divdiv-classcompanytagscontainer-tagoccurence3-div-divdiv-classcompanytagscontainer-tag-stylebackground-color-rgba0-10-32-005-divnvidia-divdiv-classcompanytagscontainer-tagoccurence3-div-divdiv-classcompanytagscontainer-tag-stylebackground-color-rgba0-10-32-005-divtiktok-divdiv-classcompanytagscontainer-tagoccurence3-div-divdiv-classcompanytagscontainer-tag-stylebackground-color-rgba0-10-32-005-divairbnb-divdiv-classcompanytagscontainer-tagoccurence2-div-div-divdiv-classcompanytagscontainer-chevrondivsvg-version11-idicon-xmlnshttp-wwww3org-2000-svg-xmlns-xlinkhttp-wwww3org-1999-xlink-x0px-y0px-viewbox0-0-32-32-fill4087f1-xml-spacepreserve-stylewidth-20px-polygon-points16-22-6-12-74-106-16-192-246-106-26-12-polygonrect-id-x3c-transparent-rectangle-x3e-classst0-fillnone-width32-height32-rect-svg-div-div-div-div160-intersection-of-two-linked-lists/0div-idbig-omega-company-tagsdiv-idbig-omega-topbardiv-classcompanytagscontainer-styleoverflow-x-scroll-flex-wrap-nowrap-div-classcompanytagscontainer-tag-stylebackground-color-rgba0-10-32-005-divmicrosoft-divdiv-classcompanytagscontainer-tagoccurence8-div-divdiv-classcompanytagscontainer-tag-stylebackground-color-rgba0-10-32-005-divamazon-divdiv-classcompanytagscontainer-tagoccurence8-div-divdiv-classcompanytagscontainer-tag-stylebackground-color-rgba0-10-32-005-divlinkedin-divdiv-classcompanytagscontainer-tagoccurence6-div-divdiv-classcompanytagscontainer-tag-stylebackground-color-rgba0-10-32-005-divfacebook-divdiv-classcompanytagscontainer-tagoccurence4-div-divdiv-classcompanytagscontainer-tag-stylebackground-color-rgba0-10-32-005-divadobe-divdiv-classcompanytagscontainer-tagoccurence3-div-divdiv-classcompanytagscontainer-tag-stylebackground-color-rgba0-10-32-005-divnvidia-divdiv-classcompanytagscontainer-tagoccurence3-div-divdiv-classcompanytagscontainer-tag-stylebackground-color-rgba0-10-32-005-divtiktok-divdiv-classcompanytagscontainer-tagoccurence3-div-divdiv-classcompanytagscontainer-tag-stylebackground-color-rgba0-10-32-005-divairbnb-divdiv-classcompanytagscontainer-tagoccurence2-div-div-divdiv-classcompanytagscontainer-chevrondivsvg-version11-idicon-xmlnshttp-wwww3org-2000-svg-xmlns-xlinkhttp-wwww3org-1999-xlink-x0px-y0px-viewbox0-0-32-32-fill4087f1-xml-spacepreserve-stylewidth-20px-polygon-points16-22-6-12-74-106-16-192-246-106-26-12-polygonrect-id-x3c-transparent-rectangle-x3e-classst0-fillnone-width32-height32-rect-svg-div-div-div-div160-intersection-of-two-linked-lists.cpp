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
    int getlen(ListNode*head){
        ListNode*temp=head;
        int len=1;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp1=headA;
          ListNode*temp2=headB;
          int l1=getlen(temp1);
          int l2=getlen(temp2);
          int diff=abs(l1-l2);
          if(l1<l2){
            while(diff>0){
                temp2=temp2->next;
                diff--;
            }
          }
            else{
                while(diff>0){
                    temp1=temp1->next;
                    diff--;
                }
            }
            while(temp1 && temp2){
                if(temp1==temp2){
                    return temp1;
                }
                temp1=temp1->next;
                 temp2=temp2->next;
            
          }
          return NULL;
    }
};