/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        stack<Node*> stk;
        Node* head0 = new Node();
        head0->next = head;
        Node* preNode = head0;
        while(head){
            //if exist a child, then we push head->next into the stack, and head->next = head->child;
            if(head->child){
                if(head->next){
                    stk.push(head->next);
                    //stk.top()->prev = NULL;
                }
                head->next = head->child;
                head->child = NULL;
            }
            //if head->next==NULL, we pop out a node from stack, and link it to head;
            else if(head->next==NULL && !stk.empty()){
                head->next = stk.top();
                stk.pop();
            }
            if(preNode!=NULL){
                head->prev = preNode;
                preNode->next = head;
            }
            preNode = head;
            head = head->next;
        }
        head0->next->prev = NULL;
        return head0->next;
    }
};
