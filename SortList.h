#include<iostream>
#include<algorithm>
#include<vector>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
class solution{
ListNode *sortList(ListNode *head) {
if (head == NULL || head->next == NULL)return head;
// 快慢指针
ListNode *fast = head, *slow = head;
while (fast->next != NULL && fast->next->next != NULL) {
fast = fast->next->next;
slow = slow->next;
}
// 分割（指向中间节点之后）
fast = slow;
slow = slow->next;
fast->next = NULL;
ListNode *l1 = sortList(head); // ࡹݼ⃤ᣁᎾ
ListNode *l2 = sortList(slow); // ऽࡹ⃤ᣁᎾ
return mergeTwoLists(l1, l2);
}
// Merge Two Sorted Lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
ListNode dummy(-1);
for (ListNode* p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
int val1 = l1 == nullptr ? INT_MAX : l1->val;
int val2 = l2 == nullptr ? INT_MAX : l2->val;
if (val1 <= val2) {
p->next = l1;
l1 = l1->next;
} else {
p->next = l2;
l2 = l2->next;
}
}
return dummy.next;
}
}