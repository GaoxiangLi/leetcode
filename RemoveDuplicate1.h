#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class solution{
	int removeDuplicate(vector<int>&nums){
		if(nums.empty()){
			return 0;
		}
		int index=0;
		for(int i=1; i<nums.size();i++){
			if(nums[index]!=nums[i])
				nums[index++]=nums[i];
		}		
		return index+1;
	}
	
	
};
//index i间隔为1 比较/替换
//       0 1 1 1 2 2 3 

