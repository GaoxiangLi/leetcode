import java.util.LinkedList;
import java.util.List;
//桶排序 只对正整数有效
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
    	int top=0;
    	for (int i = 0; i < nums.length; i++) {
			top=Math.max(top, nums[i]);
		}
        int[] res =new int[top];
        List<Integer> output=new LinkedList<>();
        for (int i = 0; i <nums.length; i++) {
			res[nums[i]]++;
		}
        for(int j=1;j<=k;j++) {
        	int max=0;
        	int pos=0;
        	for (int i = 0; i < res.length; i++) {
        		if (res[i]>max) {
					pos=i;
					max=res[i];
                    res[i]=0;
				}
        	}
        	output.add(pos);
        }
        return output;
    }
}
//map 键值对 值->次数
public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        if (nums == null) {
            return null;
        }
        
        Map<Integer, Integer> freqs = new HashMap<>();
        for (int num : nums) {
            freqs.put(num, freqs.getOrDefault(num, 0) + 1);
        }
        
        List<Map.Entry<Integer, Integer>> entries = new ArrayList<>(freqs.entrySet());
        Collections.sort(entries, new Comparator<Map.Entry<Integer, Integer>>() {
            public int compare(Map.Entry<Integer, Integer> a, Map.Entry<Integer, Integer> b) {
                return b.getValue() - a.getValue();
            }
        });
        
        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < k; i ++) {
            results.add(entries.get(i).getKey());
        }
        
        return results;
    }
}