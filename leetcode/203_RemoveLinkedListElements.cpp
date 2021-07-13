#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode* current = head;
        ListNode* last = NULL;
        while(current!=NULL){
            if(current->val == val){
                if(last == NULL){
                    head = current->next;
                    current = current->next;
                }else{
                    last->next = current->next;
                    current = current->next;
                }
            }else{
                last = current;
                current = current->next;
            }
        }
        return head;
    }
};