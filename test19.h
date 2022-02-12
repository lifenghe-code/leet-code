//
// Created by lifenghe on 2022/2/12.
//

#ifndef CLION_TEST19_H
#define CLION_TEST19_H

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
//四数之和
using namespace std;

class Solution19 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode*>store = {head};
        int num = 1;
        ListNode *Head = head;
        while(1){
            if(head->next != nullptr){
                store.push_back(head->next);
                head = head->next;
                num++;
            }
            else {
                break;
            }
        }
        if(num == 1){return NULL;}
        if(n == 1){
            store.at(num-2)->next = nullptr;
            return Head;
        }
        if(num-n == 0){
            return Head->next;
        }
        store.at(num-n-1)->next = store.at(num-n+1);
        return Head;
    }
};

#endif //CLION_TEST19_H
