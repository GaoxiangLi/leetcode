class Solution {
public:
	int mySqrt(int x) {
	int left = 1, right = x / 2;
	int last_mid; // 保存最后一次mid
	if (x < 2) return x;
	while(left <= right) {
		const int mid = left + (right - left) / 2;
		if(x / mid > mid) { // x > mid * mid会溢出
			left = mid + 1;
			last_mid = mid;
		} else if(x / mid < mid) {
			right = mid - 1;
		} else {
			return mid;
		}
	}
	return last_mid;
	}
};