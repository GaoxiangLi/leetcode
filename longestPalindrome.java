import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import net.sf.ehcache.search.aggregator.Max;

class Solution {
    public int longestPalindromeSubseq(String s) {
    	int length=s.length();
        if(length==0) {
        	return "";
        }
       int[] res= new int[length];
       res[0]=1;
       for(int i=1;i<length-2;i++) {
    	   int count=1;
    	   if(s.charAt(i-1)==s.charAt(i+1)) {
    		   for(int j=1;;j++) {
    			   if (s.charAt(i-j)==s.charAt(i+j)) {
    				   count+=2;
    			   }else {
    				   break;
    			   }
    			   if(i+j==length-1||i-j==0) {
    				   break;
    			   }
    		   }
    	   }
    	  res[i]=count;
       }
       for(int i=1;i+1<length-1;i++) {
    	   int count=0;
    	   if (s.charAt(i)==s.charAt(i+1)) {
    		   count+=2;
    		   for(int j=1;;j++) {
    			   if (s.charAt(i-j)==s.charAt(i+j+1)) {
    				   count+=2;
    			   }else {
    				   break;
    			   }
    			   if (i+j+1==length-1||i-j==0) {
					break;
    			   }
    		   }
    		   res[i]=Math.max(count, res[i]);
    	   }
       
		} 
       int result=1;
       int pos=0;
       for(int i=0;i<length;i++) {
    	   if (res[i]>result) {
			pos=i;
			result=res[i];
    	   }
		}
       if (result%2!=0) {
		 return s.substring(pos-(result-1)/2, pos+(result-1)/2);
       }
       if (result%2==0) {
		 return s.substring(pos-(result-2)/2,pos+result/2);
       }
      
      }
    
       
}

