class Solution {
public:
int jump(const vector<int>& nums) {
int result = 0;
// the maximum distance that has been reached
int last = 0;
// the maximum distance that can be reached by using "ret+1" steps
int cur = 0;
for (int i = 0; i < nums.size(); ++i) {
	if (i > last) {
		last = cur;
		++result;
	}
	cur = max(cur, i + nums[i]);
}
return result;
}
//greedy ||

class Solution {
	public:
		int jump(const vector<int>& nums) {
			int step = 0; // 保存结果
			int left = 0;
			int right = 0; // [left, right] 表示当前这一步能跳到的覆盖的区间
			if (nums.size() == 1) return 0;
				while (left <= right) { //  逐个遍历看看能跳到最远的地方 也就是说这一步可以跳到的位置
					++step;
					const int old_right = right;
					for (int i = left; i <= old_right; ++i) {
						int new_right = i + nums[i];
						if (new_right >= nums.size() - 1) return step; //区间超过范围直接结束
						if (new_right > right) right = new_right;
					}
					left = old_right + 1; //进到新的能覆盖的区间
				}
			return 0; //覆盖不到就gg
		}
};

