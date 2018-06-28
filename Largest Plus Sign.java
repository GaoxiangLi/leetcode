class Solution {    
    public int orderOfLargestPlusSign(int N, int[][] mines) {  
        int[][] dp = new int[N][N];  
        Set<Integer> mineset = new HashSet<Integer>();  
        for(int[] mine:mines){  
            mineset.add(mine[0]*N + mine[1]);//相当于对每一个mine进行编号。  
        }  
        int ans = 0;  
        for(int i = 0;i < N ;i++){  
            int count = 0;  
            for(int j = 0;j <N ;j++){  //left to right
                count = mineset.contains(i * N + j)?0:count+1;  
                dp[i][j] = count;  
            }  
            count = 0;  
            for(int j = N-1;j>=0;j--){  //right to left
                count = mineset.contains(i * N + j)?0:count+1;  
                dp[i][j] = Math.min(dp[i][j],count);  //get the minium
            }  
        }  
        for(int j = 0;j < N ;j++){  
            int count = 0;  
            for(int i = 0;i <N ;i++){  //up down
                count = mineset.contains(i * N + j)?0:count+1;  
                dp[i][j] = Math.min(dp[i][j],count);  
            }  
            count = 0;  
            for(int i = N-1;i>=0;i--){   //down up
                count = mineset.contains(i * N + j)?0:count+1;  
                dp[i][j] = Math.min(dp[i][j],count);  
                ans = Math.max(ans,dp[i][j]);  //get the minium
            }  
        }  
       return ans;   
    }  
}  
