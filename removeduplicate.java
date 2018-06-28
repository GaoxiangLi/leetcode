class Solution {
    public int removeDuplicates(int[] nums) {
    	int index=0;
        if (nums==null) {
			return index;
		}
        if (nums.length==1) {
			return 1;
		}
        for(int i=1;i<nums.length;i++) {
        	if (nums[index]!=nums[i]) {
				nums[index++]=nums[i];
			}
        }
        return index+1;
    }
}