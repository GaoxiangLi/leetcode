import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (nums.length<3||nums==null) {
			return res;
		}
        HashSet<ArrayList<Integer>> hs =new HashSet<ArrayList<Integer>>();
        Arrays.sort(nums);
        for(int i=0;i<=nums.length-3;i++) {
        	int low=i+1;
        	int high=nums.length-1;
        	
        	while(low<high) {
        		int sum=nums[i]+nums[low]+nums[high];
        		if (sum==0) {
        			ArrayList<Integer> unit =new ArrayList<Integer>();
        			unit.add(nums[i]);
        			unit.add(nums[low]);
        			unit.add(nums[high]);
        			if (!hs.contains(unit)) {
						hs.add(unit);
						res.add(unit);
					}
        			low++;
        			high--;
        		}
        		if (sum<0) {
					low++;
				}
        		if (sum>0) {
					high--;
				}
        	}
        }
        return res;
    }
}