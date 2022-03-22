#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* A) {
    ListNode* temp = new ListNode(0);
    ListNode* head = A;
    temp->next = head;
    ListNode* i = head;
    ListNode* prev = temp;

    while(i!=NULL){
        if(i->next!=NULL && (i->val > i->next->val)){
            while(prev->next!=NULL && (prev->next->val < i->next->val)) prev=prev->next;
            ListNode* newtemp = prev->next;
            prev->next = i->next;
            i->next = i->next->next;
            prev->next->next = newtemp;
            prev = temp;
        }else{
            i = i->next;
        }
    }
    return temp->next;
    
}