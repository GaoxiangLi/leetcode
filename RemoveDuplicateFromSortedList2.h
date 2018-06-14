/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//发现重复之后 从前向后删 设置一个bool值 如果bool值表示有重复 在删除完前面重复之后将最后一个删除
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return head;
		ListNode dummy(-1);
		dummy.next=head;
		ListNode *prev=&dummy;
		ListNode *cur=dummy.next;
		while(cur!=nullptr){
			bool Duplicate= false;
			for(;cur->next!=nullptr&&cur->val==cur->next->val;){
				ListNode *tmp=cur;
				cur=cur->next;
				delete tmp;
				Duplicate=true;//删除cur 将cur指向下一个 且将duplicate设为true
			}
			if(Duplicate){//删除最后一个cur
				ListNode *tmp=cur;
				cur=cur->next;
				delete tmp;
				continue;//跳出本次循环
			}
			//如果没有重复 正常遍历链表
			prev->next=cur;
			prev=prev->next;
			cur=cur->next;
			
		}
		prev->next=cur;
		return dummy.next;
    }
};