import java.util.List;

class Solution {
    public List<Integer> majorityElement(int[] nums) {
       List<Integer> result=new ArrayList<Integer>();
    	Map<Integer, Integer> bucket=new HashMap<Integer, Integer>();
        if (nums==null) {
			return null;
		}
        for (int i = 0; i < nums.length; i++) {
			int val=nums[i];
        	if (bucket.containsKey(val)) {
        		int temp=bucket.get(val);
        		temp++;
        		bucket.put(val, temp);
				if (temp==(nums.length/3+1)) {
					result.add(val);
				}
				
			}else {
				bucket.put(val, 1);
				if (nums.length<=2) {
					result.add(val);
				}
			}
		}
        return result; 
    }
}