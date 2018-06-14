class solution{
	public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()||nums.size()=0){
			return 0;	
		}
		if(nums[0]!=target&&nums.size()=1){
			return 0;
		}
		int l=0;r=nums.size()-1;
		if(l<r){
			int m=l/2+r/2;
			if(nums[m]==target){
				return m;
			}
			else if(nums[m]<target){
				l=m;
			}
			else{
				r=m;
			}
		}
		return l;
		
    }
};