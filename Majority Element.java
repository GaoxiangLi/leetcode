import java.util.HashMap;
import java.util.Map;
//hashmap实现 
class Solution {
    public int majorityElement(int[] nums) {
    
    	Map<Integer, Integer> bucket=new HashMap<Integer, Integer>();
        
        for (int i = 0; i < nums.length; i++) {
			int val=nums[i];
        	if (bucket.containsKey(val)) {
        		int temp=bucket.get(val);
        		temp++;
        		bucket.put(val, temp);
				if (temp==(nums.length/2+1)) {
					return val;
				}
			}else {
				bucket.put(val, 1);
			}
		}
        return nums[0];
    }
}

//Moore’s Voting Algorithm实现 很巧妙 伪代码 两次循环 第一次找 第二次验证
/*
 * MooreVotingAlgo(a[], size)

    // 找出候选主元素
    Initialize index and count of majority element
     maj_index = 0, count = 1
    Loop for i = 1 to size – 1
        If a[maj_index] == a[i]
            count++
        Else
            count--;
        If count == 0
            maj_index = i;
            count = 1
    // 判断候选主元素出现的次数是否大于size/2       
    count = 0
    Loop for i = 1 to size - 1
        if a[i] == a[maj_index]
            ++count;
        if count > size/2 
            return a[maj_index]
    return -1;
 */



