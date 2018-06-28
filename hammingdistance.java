import java.util.Iterator;

class Solution {
    public int hammingDistance(int x, int y) {
    	int i=x^y;
    	int count=0;
    	while(i!=0) {
    		if (i%2==1) {
				count++;
			}
    		i=i/2;
    	}
    	
    	return count;

    }
   
}