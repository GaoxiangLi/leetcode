#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
	public:
		void merge(vector<int> &A,int n, vector<int> &B,int m){
			
			int cur=m+n-1;
			int ia=n-1,ib=m-1;
			while(ia>0&&ib>0){
				if(A[ia]>=B[ib]){
					A[cur--]=A[ia--];
					
				}else{
					A[cur--]=B[ib--];
					
				}	
			}
			while(ib>0){
				A[cur--]=B[ib--];
			}
			
		}
	
	
	
	
	
	
};