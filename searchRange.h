class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res;
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            if(nums[l] < target) {
                ++l;
            } 
            if(nums[r] > target) {
                --r;
            }
            if(nums[l] == target && nums[r] == target) {
                res.push_back(l);
                res.push_back(r);
                return res;
            }
        }
        if(res.empty())
        {
        res.push_back(-1);
        res.push_back(-1);
        return res;
        }
    }
};
//二分查找 左右查找夹逼 