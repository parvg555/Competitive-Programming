#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* A, int B) {
    ListNode* CurrentSmall = NULL;
    ListNode* CurrentBig = NULL;
    ListNode* SmallHead = NULL;
    ListNode* BigHead = NULL;
    while(A!=NULL){
        if(A->val < B){
            if(CurrentSmall==NULL) CurrentSmall = new ListNode(A->val);
            else{
                CurrentSmall->next = new ListNode(A->val);
                CurrentSmall = CurrentSmall->next;
            }
            if(SmallHead == NULL) SmallHead = CurrentSmall;
        }else{
            if(CurrentBig==NULL) CurrentBig = new ListNode(A->val);
            else{
                CurrentBig->next = new ListNode(A->val);
                CurrentBig = CurrentBig->next;
            }
            if(BigHead == NULL) BigHead = CurrentBig;
        }
        A = A->next;
    }
    if(SmallHead==NULL){
        return BigHead;
    }
    CurrentSmall->next = BigHead;
    return SmallHead;
}