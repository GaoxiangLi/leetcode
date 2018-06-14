class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> f(nums.size(),0);
		for(int i=1;i<nums.size();i++){
			f[i]=max(f[i-1]-1,nums[i-1]-1);
			if(f[i]<0) return false;
		}
		return f[nums.size()-1]>=0;
    }
};
//f[i] = max(f[i − 1], A[i − 1]) − 1, i > 0 动态规划状态方程