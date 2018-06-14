//两个有序数组 找到第K大的元素
//比较 A[k/2-1] B[k/2-1]
#include<iostream>
#include<vector>
using namespace std;
class solution{
	public: double FindNoKInTwoSortArray(int array1[],int len1,int array2[],int len2,int k){
		
		if(k<0){
			return -1;
		}
		if(k==1){
			return min(array1[0],array2[0]);
		}
		if(len1>len2){
			return FindNoKInTwoSortArray(array2,len2, array1,len1, k);
		}
		int num1=(len1>k/2)?k/2:len1;
		int num2=k-num1;
		if(array1[num1-1]==array2[num2-1]){
			return array1[num1-1];
		}
		else if(array1[num1-1]<array2[num2-1]){
			return FindNoKInTwoSortArray(&array1[num1],len1-num1,array2,len2,k-num1);
		}
		else if(array1[num1-1]>array2[num2-1]){
			return FindNoKInTwoSortArray(array1,len1,&array2[num2],len2-num2,k-num2);
		}
	}
};
int main()  
{  
    solution s;  
    int ret;  
    int i;  
    int array1[11] = {0,1,2,3,4,5,6,7,8,9,17};  
    int array2[11] = {3,4,5,6,7,8,9,10,11,12,29};  
  
    cout<<"sorted two array:"<<endl;  
    for(i=1; i<=22; i++)  
    {  
        ret = s.FindNoKInTwoSortArray(array1, 11, array2,11, i);  
        cout<<i<<"th: "<<ret<<endl;  
    }  
}    