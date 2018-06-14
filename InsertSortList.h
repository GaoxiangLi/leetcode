#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//分为两部分 一部分已经排序 一部分等待排序
class solution{
	ListNode* sortList(ListNode* head) {
    // 注意这样写，是不需要额外判断head是否为NULL的
    ListNode *newHead = NULL, *toInsert = head;
    while (toInsert != NULL) {
        ListNode *current = newHead, *last = NULL, *next = toInsert->next;
        // 从头往后找到第一个大于toInsert->value的元素
        while (current != NULL && current->val <= toInsert->val) {
            last = current;
            current = current->next;
        }

        if (last == NULL) {
            // 如果比任何已排序的数字都要小，那么就成为新的头部
            toInsert->next = newHead;
            newHead = toInsert;
        } else {
            // 否则插入到last的后面
            toInsert->next = last->next;
            last->next = toInsert;
        }

        toInsert = next;
    }
    return newHead;
	}
	
	
	
};