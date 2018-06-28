import java.util.Collections;

class Solution {
    public void moveZeroes(int[] nums) {
        for (int i = 0; i < nums.length-1; i++) {
			if (nums[i]==0) {
				for (int j = i+1;j<nums.length; j++) {
					if (nums[j]!=0) {
						
						int temp=0;
						temp=nums[j];
						nums[j]=nums[i];
						nums[i]=temp;
						break; //keep the relative order, so only do one swap operation for one i
					}
				}
			}
		}
    
    }
}