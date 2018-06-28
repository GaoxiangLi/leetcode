import java.util.ArrayList;
import java.util.Collections;
import java.util.List;



class Solution {
	List<List<Integer>> res=new ArrayList<List<Integer>>();
    public List<List<Integer>> permute(int[] nums) { 												
        int length=nums.length;
        if (nums==null) {
			return null;
		}
        exchange(nums,0,length);
        return res;
    }
    public void exchange(int[] nums,int i, int len) {
		if (i==len-1) {//直到分到最后
			List<Integer> list=new ArrayList<>();
			for (int j = 0; j < nums.length; j++) {
				list.add(nums[j]);//直接加入结果
			}
			res.add(list)
			return ;
		}
		for(int j=i;j<len;j++) {//拿1234举例 exchange 0，4 第一次swap得到四个结果 分别把 1 2 3 4换到第一位
			swap(nums, i, j);	// 然后以这四个为基准 （i相当于位置标记） 做exchange i+1 4的操作  在每一个基础上再细分 
			exchange(nums, i+1, len);
			swap(nums, i, j);//换完了再换回去保持数组不变
		}
	}
    public void swap(int[] nums,int i,int j) {//很简单 不解释了
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
}