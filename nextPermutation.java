public class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        if (len<2)  return ;

        int[] res = new int [len];

        /* 从倒数第二个元素开始，从后向前，找到第一个满足(后元素>前元素)的情况
         * 此时，记录前元素下标k，则[k+1,n-1]为一个单调非增子序列
         * 那么，这里只需要将一个比nums[k]大的最小数与nums[k]交换
         * 1 1 5 1 3 2
         */
        int lastEle = nums[len-1];
        int k = len-2;
        for (; k>=0; k--){
            if (lastEle > nums[k])  break;
            else {
                lastEle = nums[k];
                continue;
            }
        }

        // 当前排列为最大排列，逆序之
        if (k<0) {
            for (int i=0; i<(len+1)/2; i++) {
                swap(nums, i, len-1-i);
            }
        } else {
            // 在nums[k+1,n-1]中寻找大于nums[k]的最小数
            int index=0;
            for (int i=len-1; i>k; i--) {
                if (nums[i]>nums[k]) {
                    swap(nums, i, k);
                    index=i;
                    break;
                }
            }
            // index为0，表示当前nums[k]小于其后任意一个数，直接交换k与len-1
            if (index==0){
                swap(nums, k, len-1);
            }
            // 将nums[k+1,n-1]逆序
            for (int i=k+1; i<(k+len+2)/2; i++) {
                swap(nums, i, k+len-i);
            }
        }
        return ;
    }
    // 交换元素
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
