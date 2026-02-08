/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
//o filho do primeiro nó a direita é o mais a direita e o da esquerda é o primeiro a esquerda na lista 

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(head == NULL){ // caso a lista seja vazia
        return NULL;
    } 
    if(head->next == NULL) { // caso só tenha um elemento ou seja nulo
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = head->val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = head;
    do{ // acha o ultimo valor da lista, o meio da lista e o anterior
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != NULL && fast->next != NULL); // garante que o while vai parar quando for o ponto ideal
    
    prev->next = NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // aloca o novo nó
    node->val = slow->val; 
    //recursão para montar a arvore
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next); 

    return node; //retorna endereço do node
}
    
