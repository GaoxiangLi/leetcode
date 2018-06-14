#include<iostream>
#include<vector>
using namespace std;
class solution{
	int searchRotateArray(const vector<int>&nums, int target){
		int first=0, last=nums.size();
		if(first!=last){
			const int mid= (first+last)/2;
			if(target==nums[mid]){
				return mid;
			}
			if(nums[first]<nums[mid]){
				if(target<nums[mid]&&target>=nums[first]){
					last= mid;
				}
				else{ 
				first= mid+1;
				}
			}else{
				if(target>nums[mid]&&target<=nums[last]){
					first= mid+1;
				}
				else {
				last= mid;
				}
			}
			
		}else return -1;
	}
};

//first和mid比较 如果first小于mid，说明mid左边是单调递增序列； 如果first大于mid，说明mid右边是单调递增序列。 然后检查是否在单调序列当中。