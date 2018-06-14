#include<iostream>
#include<vector>
using namespace std;
class solution{
	int removeDuplicate(vector<int>& nums){
		if(nums.size()<2){
			return nums.size();
		}
		int index=1;
		for(int i=2; i<nums.size();i++){
			if(nums[index-1]!=nums[i])
				nums[index++]=nums[i];
		}		
		return index;
	}
	
	
};
//间隔为2（允许重复）