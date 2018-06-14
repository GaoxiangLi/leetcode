/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //先计算list长度length，使首尾相连成环 再在对应位置断开
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p=head;
		int length=1;
		if(k==0||head==nullptr) return head;
		for(;p->next!=nullptr;p=p->next){
			length++;
		}
		k=length-k%length;
		p->next=head;
		for(int i=0;i<k;i++){
			p=p->next;
		}
		head=p->next;
		p->next=nullptr;
		return head;
    }
};