/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* swap(struct ListNode * current, int k, struct ListNode ** firstr, struct ListNode ** next){
    if(current!=NULL){
        if(k!=0){
            struct ListNode * n = swap(current->next, k-1, firstr, next);
            if(n!=NULL){    
                n->next = current;
                return current;
            }
            return NULL;
        }
        *firstr=current;
        *next=current->next;
        return current;
    }
    return NULL;
 }
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* current=head, *prev, *next;
    while(current!=NULL){
        struct ListNode * firstr;
        struct ListNode * lastr = swap(current, k-1, &firstr, &next);
        
        if(lastr!=NULL){
            if(current==head){
                head=firstr;
            }
            else{
                prev->next=firstr;
            }
            lastr->next=next;
            prev=lastr;
            current=next;
        }
        else{
            break;
        }
    }
    return head;
}
