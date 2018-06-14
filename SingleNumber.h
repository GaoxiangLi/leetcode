// x^ 异或运算相等则为0   (xor)
class solution{
	public:
		int singleNumber(vector<int>& nums) {
		int x = 0;
		for (auto i : nums) {
			x ^= i;
		}
		return x;
	}
};