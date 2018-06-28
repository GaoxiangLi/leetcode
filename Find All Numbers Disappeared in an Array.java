import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int[] bucket=new int[nums.length+1];
        for (int i = 0; i < nums.length; i++) {
			bucket[nums[i]]=1;
		}
        List<Integer> result=new ArrayList<>();
        result.add(0);
        for (int i = 1; i < bucket.length; i++) {
			if (bucket[i]!=1) {
				result.add(i);
			}
		}
        return result;
    }
}