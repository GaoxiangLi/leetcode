//限定空间 用数组本身桶排序 swap A[i] and A[A[i]-1]
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class solution{
	 public:
		int firstMissingPositive(vector<int>& nums) {
		bucket_sort(nums);
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != (i + 1)){
				return i + 1;
			}
		return nums.size() + 1;
		}
	private:
		static void bucket_sort(vector<int>& A) {
		const int n = A.size();
			for (int i = 0; i < n; i++) {
				while (A[i] != i + 1) {//是否已经满足条件 不满足则交换
					if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]){
						break;
					}
				swap(A[i], A[A[i] - 1]);
				}
			}
		}
};