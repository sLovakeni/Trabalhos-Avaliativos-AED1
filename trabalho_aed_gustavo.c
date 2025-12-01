/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode *before=head;
    struct ListNode *after=head->next;

    while(after && after->next){
        before = before->next;
        after = after->next->next;
    }
    struct ListNode* second = before->next;
    struct ListNode* ant = before->next=NULL;

    while(second){
        struct ListNode* temp=second->next;
        second->next = ant;
        ant = second;
        second = temp;
    }
    struct ListNode* first = head;
    second = ant;
    while(second){
        struct ListNode *temp1=first->next;
        struct ListNode *temp2=second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}
