#include<iostream>
#include<vector>
#include<algorithm>
/*递归实现 */
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
			int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
 };
class solution{
	ListNode *MergeTwoSortedList(ListNode *L1, ListNode * L2){
		if(L1==nullptr)
			return L2;
		if(L2==nullptr)
			return L1;
		if(L1->val>L2->val){
			ListNode *temp=L2;
			temp->next=MergeTwoSortedList(L1,L2->next);
			return temp;
		}else{
			ListNode *temp=L1;
			temp->next=MergeTwoSortedList(L1->next,L2);
			return temp;
		}
		
		
	}
	
	
	
};