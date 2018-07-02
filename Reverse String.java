import java.util.Collections;

class Solution {
    public String reverseString(String s) {
    	public String reverseString(String s) {
    		char[] res = s.toCharArray();
    	        int i = 0, j = s.length() - 1;

    	        while (i < j){
    	            char t = res[i];
    	            res[i++] = res[j];
    	            res[j--] = t;
    	        }

    	        return String.valueOf(res);
    	}
    }
}