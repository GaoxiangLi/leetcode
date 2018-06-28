#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Maximum Subarray 求最大连续子段和
//f(j)为状态 S(j)最大子段和 dp方程 f(j)=max(f(j-1)+S(j),S(j))
//f(j-1)+S(j) 如果该值小于0 则放弃 开始新的子段
class solution{
	int maxSubarray(vector<int> &nums){
		int result=nums[0],f=0;
		for(int i=0;i<nums.size();i++){
			f=max(f+nums[i],nums[i]);
			result=max(f,result);
		}
		return result;
		
	}



};