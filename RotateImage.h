// LeetCode, Rotate Image
// O(n^2)  O(1)
class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
const int n = matrix.size();
for (int i = 0; i < n / 2; ++i) //先上下对换
for (int j = 0; j < n; ++j)
swap(matrix[i][j], matrix[n - 1 - i][j]);
for (int i = 0; i < n; ++i) // 再按对角线对换
for (int j = i + 1; j < n; ++j)
swap(matrix[i][j], matrix[j][i]);
}
};

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n=matrix.size();
		for(int i=0;i<n/2;i++){
			for(int j=0;j<n;j++){
				swap(matrix[i][j],matrix[n-1-i][j]);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				swap(matrix[i][j],matrix[j][i]);	
			}	
		}
	}
};