#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> mapping;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			mapping[nums[i]] = i;
			}
		for (int i = 0; i < nums.size(); i++) {
			const int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;
	}
};
//用hash存储下标 sum-当前值=gap 查找gap
//键值对 下标->数值