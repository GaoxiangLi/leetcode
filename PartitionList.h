/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} //已经定义的结构体直接用".",不需要"->";
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);//小于X的头结点
		ListNode right_dummy(-1);//大于X的头节点
		auto left_cur=&left_dummy;
		auto right_cur=&right_dummy;
		for(ListNode *cur=head;cur!=nullptr;cur=cur->next){
			if(cur->val <x){
				left_cur->next=cur;
				left_cur=left_cur->next;
			}else{
				right_cur->next=cur;
				right_cur=right_cur->next;
			}
		}
		left_cur->next=right_dummy.next;
		right_cur->next=nullptr;
		return left_dummy.next;
    }
};
//小的放左边 大的放右边 左右连起来