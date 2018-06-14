#include <iostream>  
using namespace std;  
  
class solution  
{  
public:  
    /*在两个升序排序的数组中找到第k大的元素*/  
    int FindKthInTwoSortedArray(int array1[], int len1, int array2[],int len2, int k)  
    {     
        if( k < 0 )  
        {  
            cout<<"Invalid k = "<<k<<endl;  
            return -1;  
        }  
        /*保证 len1 <= len2*/  
        if( len1 > len2 )  
            return FindKthInTwoSortedArray(array2,len2, array1,len1, k);  
        if( len1 == 0 )  
            return array2[k-1];  
        if( k == 1)  
            return ((array1[0]>= array2[0]) ? array2[0] : array1[0]);  
  
        /*不一定每个数组都有k/2个元素*/  
        int num1 = (len1 >= k/2) ? k/2 : len1;  
        int num2 = k - num1;   
          
          
        if( array1[num1-1] == array2[num2-1] )  
            return array1[num1-1];  
        else if( array1[num1-1] > array2[num2-1] )  
        {  
            return FindKthInTwoSortedArray(array1, len1, &array2[num2], len2-num2, k-num2);  
        }  
        else if( array1[num1-1] < array2[num2-1] )  
        {  
            return FindKthInTwoSortedArray(&array1[num1], len1-num1, array2, len2, k-num1);  
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
        ret = s.FindKthInTwoSortedArray(array1, 11, array2, 11, i);  
        cout<<i<<"th: "<<ret<<endl;  
    }  
}    