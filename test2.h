#pragma once
class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* result = new ListNode(0);
        head = result;
        int carry = 0;
        while(true){
            ListNode* tmp = new ListNode();
            tmp->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            result->next = tmp;
            result = result->next;
            if(l1->next == nullptr){
                break;
            }
            else ;
            if(l2->next == nullptr){
                break;
            }
            else {
                l1 = l1->next; l2 = l2->next;continue;
            }
        }
        if(l1->next == nullptr && l2->next != nullptr){
            while(true){
                ListNode* tmp = new ListNode();
                l2 = l2->next;
                tmp->val = (l2->val + carry)%10;
                carry = (l2->val + carry)/10;
                result->next = tmp;
                result = result->next;
                if(l2->next != nullptr) continue;
                else {
                    if(carry == 0)
                    return head->next;
                    else {
                    ListNode* tmp = new ListNode(1);
                    result->next = tmp;
                    return head->next;
                    }
                }
            }
        }
        else if(l1->next != nullptr && l2->next == nullptr){
            while(true){
                ListNode* tmp = new ListNode();
                l1 = l1->next;
                tmp->val = (l1->val + carry)%10;
                carry = (l1->val + carry)/10;
                result->next = tmp;
                result = result->next;
                if(l1->next != nullptr) continue;
                else {
                    if(carry == 0)
                    return head->next;
                    else {
                    ListNode* tmp = new ListNode(1);
                    result->next = tmp;
                    return head->next;
                }
                }
            }
        }
        else if(l1->next == nullptr && l2->next == nullptr){
            if(carry == 0)
                return head->next;
            else {
                ListNode* tmp = new ListNode(1);
                result->next = tmp;
                return head->next;
            }
        }
        else {return head->next;}
    }
};
