/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//The K Linked lists are already sorted, so it is better to use the idea of merge sort. 
//1. I use the divide and conquer to save the time complexity.
//1.1 Each time, we merge the last one list with the first one list, store it in the first place. And merge the second one of the end with the second one of the start, store it in the second place. 
//1.2 recursively repeat the process until there is only one list, and that is what we want.
//In my method, the time complexity is O(NlogK), and space complexity is O(1).

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *head0 = new ListNode(0);
        ListNode *tail = head0;
        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        else if(l2) tail->next = l2;
        return head0->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int len = lists.size();
        while(len>1){
            for(int i=0; i<len/2; ++i){
                lists[i] = mergeTwoLists(lists[i], lists[len-i-1]);
            }
            len = len - len/2;
        }
        return lists[0];
    }
};
