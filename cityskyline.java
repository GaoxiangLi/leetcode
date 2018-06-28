class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
    	int x=grid.length;
        int[] left = new int[x];
        int[] right = new int[x];
        
        for(int i=0;i<x;i++) {
        
        	for(int j=0;j<x;j++) {
 
        		left[i]=Math.max(left[i], grid[i][j]);
        		
        	}
        }
        
        for(int j=0;j<x;j++) {
        	
        	for(int i=0;i<x;i++) {
    
        		right[j]=Math.max(right[j], grid[i][j]);
        		
        	}
        }
        
        int res=0;
        for(int i=0;i<x;i++) {
        	for(int j=0;j<x;j++) {
        		res+=Math.min(left[i], right[j])-grid[i][j];
        	}
        }
        return res;
    }
}