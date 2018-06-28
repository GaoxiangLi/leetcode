import java.util.HashMap;

class solution{
	public int[] twosum(int[] numbers,int target) {
		int[] res=new int[2];
		if(numbers.length<2||numbers==null) {
			return res;
		}
		HashMap<Integer, Integer>map=new HashMap<Integer,Integer>();
		for(int i=0;i<numbers.length;i++) {
			if (!map.containsKey(target-numbers[i])) {
				map.put(numbers[i], i);
			}else {
				res[0]=map.get(target-numbers[i]);
				res[1]=i;
				break;
			}
		}
		return res;
	}
}