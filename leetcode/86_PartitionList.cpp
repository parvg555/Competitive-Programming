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
    ListNode* partition(ListNode* head, int x) {
        ListNode* Head1 = NULL;
        ListNode* End1 = NULL;
        ListNode* Head2 = NULL;
        ListNode* End2 = NULL;
        if(head==NULL){
            return NULL;
        }
        while(head!=NULL){
            ListNode* temp = new ListNode();
            temp->val = head->val;
            if(head->val<x){
                if(Head1 == NULL && End1 == NULL){
                    Head1 = temp;
                    End1 = temp;
                }else{
                    End1->next = temp;
                    End1 = End1->next;
                }
            }else{
                if(Head2 == NULL && End2 == NULL){
                    Head2 = temp;
                    End2 = temp;
                }else{
                    End2 -> next = temp;
                    End2 = End2 -> next;
                }
            }
            head = head->next;
        }
        if(End1!=NULL){
            End1->next = Head2;
            return Head1;
        }
        return Head2;
    }
};